#ifndef CL_2_H
#define CL_2_H
#include "cl_base.h"

class cl_2: public cl_base{
public:
  cl_2();
  void get_name_addr(string s);
  static void hendler_1(cl_base* p_ob, string &s_text);
  static void hendler_2(cl_base* p_ob, string &s_text);
};
#endif
