#include "tri.h"
#include <cmath>
tri::tri(int d, int e, int f){
  a = d;
  b = e;
  c = f;
}
double tri::perim(){
  return a+b+c;
}
double tri::area(){
  double p = perim()/2;
  return sqrt(p*(p-a)*(p-b)*(p-c));
}
