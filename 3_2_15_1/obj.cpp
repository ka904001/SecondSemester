#include "obj.h"
#include <iostream>
#include <limits>
using namespace std;

void maxint(first &one, second &two) {
  int max = std::numeric_limits<int>::min();
  if (one.a > max)
    max = one.a;
  if (two.b > max)
    max = two.b;
  if (two.c > max)
    max = two.c;
  cout << max;
}

first::first(int b){
  a = b;
}
void second::input(){
  cin>>b>>c;
}
