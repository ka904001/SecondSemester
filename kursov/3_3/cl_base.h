#ifndef CL_BASE_H
#define CL_BASE_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define SIGNAL_D(signal_f) ((void (*)(string &))(&(signal_f)))
#define HENDLER_D(hendler_f) ((void (*)(cl_base *, string &))(&(hendler_f)))
using namespace std;
class cl_base {
public:
  void set_connect(void (*p_signal)(string &), cl_base *,
                   void (*p_hendler)(cl_base *, string &));
  // void delete_connect(void (*p_signal)(), cl_base *,
  //                     void (*p_hendler)(cl_base *, fstream &, string));
  void emit_signal(void (*p_signal)(string &), string &s_command);

  cl_base(cl_base *p_parent = 0);
  void set_object_name(string object_name);
  string get_object_name();
  string get_path_item(string object_path, int i_level);
  void set_parent(cl_base *p_parent);
  void add_child(cl_base *p_child);
  void delete_child(string object_name);
  void set_state(int);
  cl_base *get_child(string object_name);
  cl_base *get_object_root();
  cl_base *get_object(string object_path);
  vector<cl_base *> children; // ссылки на потомков
  vector<cl_base *>::iterator it_child;
  int state;
private:
  struct o_sh {
    cl_base *p_cl_base;
    void (*p_hendler)(cl_base *p_ob, string &);
  };
  multimap<void (*)(string &), o_sh *> connects;
  multimap<void (*)(string &), o_sh *>::iterator it_connects;
  string object_name; // наименование объекта
  cl_base *p_parent;  // ссылка на головной объект
};
#endif
