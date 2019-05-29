#include "cl_3.h"

cl_3::cl_3() { set_state(1); }
void cl_3::hendler_1(cl_base *p_ob, string &s_text) {
  cout << endl
       << "Object name: " << p_ob->get_object_name() << " Text: " << s_text;
}
