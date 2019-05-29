#ifndef CL_POS_H
#define CL_POS_H

#include "cl_base.h"

class cl_pos : public cl_base {
public:
  void work_position(int &, int &, char &);
  static void position_secure(char &){};
};

#endif
