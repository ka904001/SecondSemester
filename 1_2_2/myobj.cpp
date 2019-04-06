#include "myobj.h"
#include <iostream>
myobj::myobj(int n){
  p = new int[n];
  l = n;
}
myobj::~myobj(){
  delete []p;
}
void myobj::input(){
  for(int i = 0; i<l; i++){
    std::cin>>p[i];
  }
}
void myobj::output(){
  for(int i = 0; i<l; i++){
    std::cout.width(5);
    std::cout<<p[i];
  }
}
void myobj::reverse(){
  for(int i = 0; i<l/2; i++){
    int t = p[i];
    p[i]=p[l-1-i];
    p[l-1-i]=t;
  }
}
void myobj::show_l(){
  std::cout<<"N = "<<l<<std::endl;
}
