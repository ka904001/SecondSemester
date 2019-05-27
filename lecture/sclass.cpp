#include "sclass.h"
void base::set_name(string na){
  name = na;
}
string base::get_name(){
  return name;
}
void base::set_parent(base* p){
  if(p){
    this->parent = p;
    p->adopt_child_wp(this);
  }
}
void base::adopt_child_wp(base * p){
  if(p){
    this->children.push_back(p);
  }
}
