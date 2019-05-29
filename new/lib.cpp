#include "lib.h"
// #define SIGNAL_D(signal_f) ((void (*)(string))(&(signal_f)))
// #define HENDLER_D(hendler_f) ((void (*)(cl_base *, string))(&(hendler_f)))

cl_base ::cl_base(cl_base *p_parent) {
  set_object_name("cl_base");

  if (p_parent) {
    this->p_parent = p_parent;
    p_parent->add_child(this);
  }
}

void cl_base ::set_object_name(string object_name) {
  this->object_name = object_name;
}

void cl_base ::set_parent(cl_base *p_parent) {
  if (p_parent) {
    this->p_parent = p_parent;
    p_parent->add_child(this);
  }
}
void cl_base ::add_child(cl_base *p_child) { children.push_back(p_child); }

void cl_base ::delete_child(string object_name) {
  if (children.size() == 0)
    return;
  it_child = children.begin();
  while (it_child != children.end()) {
    if ((*it_child)->get_object_name() == object_name) {
      children.erase(it_child);
      return;
    }
    it_child++;
  }
}
cl_base *cl_base ::get_child(string object_name) {
  if (children.size() == 0)
    return 0;
  it_child = children.begin();
  while (it_child != children.end()) {
    if ((*it_child)->get_object_name() == object_name) {
      return (*it_child);
    }
    it_child++;
  }

  return 0;
}
string cl_base ::get_path_item(string object_path, int i_level) {
  int i_item_start, i_item_end, i_lc;
  i_lc = i_item_start = 1;
  while (i_item_start) {
    i_item_end = object_path.find('/', i_item_start);
    if (i_lc == i_level)
      return object_path.substr(i_item_start, i_item_end - i_item_start);
    i_lc++;
    i_item_start = i_item_end + 1;
  }
  return "";
}
cl_base *cl_base ::get_object_root() {
  cl_base *p_parent_previous; // ссылка на очередной головной объект
  //----------------------------------------------------------------
  if (object_name == "root")
    return this;
  p_parent_previous = p_parent;
  while (p_parent_previous->p_parent) {
    p_parent_previous = p_parent_previous->p_parent;
  }
  return p_parent_previous;
}
cl_base *cl_base ::get_object(string object_path) {
  string s_path_item;
  cl_base *p_parent_next; // ссылка на очередной головной объект
  cl_base *p_child; // ссылка на очередной подчиненный объект
  int i_level_next = 2;
  //------------------------------------------------------------------
  p_parent_next = get_object_root();
  s_path_item = get_path_item(object_path, 1);
  if (s_path_item != "root")
    return 0;
  s_path_item = get_path_item(object_path, i_level_next);
  while (!s_path_item.empty()) {
    p_child = p_parent_next->get_child(s_path_item);
    if (p_child) {
      p_parent_next = p_child;
      i_level_next++;
      s_path_item = get_path_item(object_path, i_level_next);
    } else {
      return 0;
    }
  }
  return p_parent_next;
}
void cl_base ::set_connect(void (*p_signal)(string &), cl_base *p_ob_hendler,
                           void (*p_hendler)(cl_base *, string &)) {
  void (*p_key)(string &);
  o_sh *p_value;
  if (connects.size() > 0) {
    it_connects = connects.begin();
    while (it_connects != connects.end()) {
      p_key = it_connects->first;
      p_value = it_connects->second;
      if (((p_key) == p_signal) && (p_value->p_cl_base) == p_ob_hendler &&
          ((p_value->p_hendler) == p_hendler))
        return;
      it_connects++;
    }
  }
  p_value = new o_sh;
  p_value->p_cl_base = p_ob_hendler;
  p_value->p_hendler = p_hendler;
  connects.insert({p_signal, p_value});
}
// void cl_base ::delete_connect(void (*p_signal)(string), cl_base
// *p_ob_hendler,
//                               void (*p_hendler)(cl_base *p_ob, fstream &,
//                                                 string)) {
//   if (connects.empty())
//     return;
//   if (connects.count(p_signal) == 0)
//     return;
//   it_connects = connects.find(p_signal);
//   while (it_connects != connects.end()) {
//     if ((it_connects->first) == p_signal &&
//         (it_connects->second->p_hendler) == p_hendler &&
//         (it_connects->second->p_cl_base == p_ob_hendler)) {
//       connects.erase(it_connects);
//       return;
//     }
//     it_connects++;
//   }
// }
void cl_base::emit_signal(void (*p_signal)(string &), string &s_command) {
  void (*p_hendler)(cl_base * p_ob, string &);
  if (connects.empty())
    return;
  if (connects.count(p_signal) == 0)
    return;
  (p_signal)(s_command);
  it_connects = connects.begin();
  while (it_connects != connects.end()) {
    if ((it_connects->first) == p_signal) {
      p_hendler = it_connects->second->p_hendler;
      (p_hendler)(it_connects->second->p_cl_base, s_command);
    }
    it_connects++;
  }
}
void application::init() {
  p_set = new set_position;
  p_write = new write_to_file;
  string command;
  file.open("field.txt", ios::out);
  p_set->set_connect((p_set->correct_position()), p_write, (hendler()));
}
void application::exec() {
  p_write->first_output(file);
  int a, b;
  string c;
  cin >> a >> b >> c;
  while (a != 0 && b != 0) {
    p_set->set(file, a, b, c);
    cin >> a >> b >> c;
  }
}
void hendler(write_to_file *p_ob, fstream &file, string &command) {
  p_ob->write_to_position(file, command);
}
void set_position::set(fstream &file, int a, int b, string c) {
  if ((a >= 1 && a <= 10) && (b >= 1 && b <= 10)) {
    file.seekp(20 * a + b - 1, ios_base::cur);
    emit_signal(correct_position(), file, c);
  } else {
    file.seekp(0, ios_base::end);
    file << "Coordinate is wrong (" << a << ',' << b << ")\n";
  }
}
void write_to_file::write_to_position(fstream &file, string &command) {
  if ((command >= "a" && command <= "z") ||
      (command >= "A" && command <= "Z")) {
    file << command;
  } else {
    file.seekp(0, ios_base::end);
    file << "Not the letter of the Latin alphbet\n";
  }
}
void write_to_file::first_output(fstream &file) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      file << "8";
      if (j != 9)
        file << " ";
    }
    file << endl;
  }
}
// void cl_application ::show_object_state() { show_state_next(this); }
// void cl_application ::show_state_next(cl_base *ob_parent) {
//   if (ob_parent->get_state() == 1) {
//       cout << "The object " << ob_parent->get_object_name() << " is ready"
//            << endl;
//   } else {
//       cout << "The object " << ob_parent->get_object_name() << " is not
//     ready"
//            << endl;
//   }
//     if (ob_parent->children.size() == 0) return;
//     ob_parent->it_child = ob_parent->children.begin();
//     while (ob_parent->it_child != ob_parent->children.end()) {
//       show_state_next((*(ob_parent->it_child)));
//       ob_parent->it_child++;
//   }
// }
