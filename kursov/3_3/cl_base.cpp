#include "cl_base.h"
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
string cl_base ::get_object_name() { return object_name; }

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
void cl_base::set_state(int a) { state = a; }
