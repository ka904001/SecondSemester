#include "cl_write.h"
void cl_write::hendler_pos_secure(cl_base *p_ob, char &c) {
  if ((c > 'a' && c < 'z') || (c > 'A' && c < 'Z')) {
    ((p_ob->get_root())->get_stream()) << c;
  } else {
    ((p_ob->get_root())->get_stream()).seekp(0, ios_base::end);
    ((p_ob->get_root())->get_stream())
        << endl
        << "Not a letter of the Latin alphabet: " << c;
  }
}
// void cl_write::hendler_pos_failure(cl_base *p_ob, string &some) {
//   ((p_ob->get_root())->get_stream()) << "";
// }
