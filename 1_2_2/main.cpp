#include <iostream>
#include "myobj.h"
using namespace std;

int main(){
  int n;
  cin>>n;
  myobj here{n};
  here.input();
  here.show_l();
  here.output();
  cout<<endl;
  here.reverse();
  here.output();
  return 0;
}
