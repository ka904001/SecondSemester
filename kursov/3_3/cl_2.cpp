#include "cl_2.h"
cl_2::cl_2() { set_state(0); }
void cl_2::get_name_addr(string s) {
  cout
      << endl
      << "Object  name: "
      << "Not working with static" /*(this->get_object(s))->get_object_name()*/;
}
void cl_2::hendler_1(cl_base *p_ob, string &s_text) {
  cout << endl
       << "Object name: " << p_ob->get_object_name() << " Text: " << s_text;
}
void cl_2::hendler_2(cl_base *p_ob, string &s_text) {
  cout << endl
       << "Object name: " << p_ob->get_object_name() << " Text: " << s_text;
}
