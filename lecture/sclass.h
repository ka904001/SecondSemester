#ifndef SCLASS_H
#define SCLASS_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class base{
private:
  base* parent;
  string name;
public:
  base(): parent(0){};
  base(base* p): parent(p){};
  void set_name(string);
  void set_parent(base*);
  string get_name();
  void adopt_child_wp(base*);
  void abandon_child(base*);
  base * get_child(string);
  base * get_obj(string);

  std::vector<base*> children;
  std::vector<base*>::iterator child_iter;
};

#endif
