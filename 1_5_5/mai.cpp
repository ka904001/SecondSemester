#include <iostream>
#include "tri.h"
using namespace std;
int main(){
  int a, b, c;
  cin>>a>>b>>c;
  tri am{a, b, c};
  cout<<am.perim()<<endl;
  cout<<am.area();
  return 0;
}
