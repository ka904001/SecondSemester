#ifndef NCLASS_H
#define NCLASS_H
#include "sclass.h"

class nclass : public base
{
public:
  nclass();
  void build_tree();
  void show_tree();
  int exec_app();
};

#endif
