#include <iostream>
#include "obj.h"
using namespace std;
void obj::input(){
  cin>>a;
}

void obj::count(){
  int64_t m = a;
  n = 0;
  if(m == 0){
    n = 1;
  }
  while(m != 0){
    m /= 10;
    n++;
  }
}

void obj::output(){
  cout << "n = "<<a<<endl;
  cout << "N = "<<n;
}
