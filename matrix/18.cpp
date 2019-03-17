#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
  double n = 31.0;
  double xs = 1, x = 0;
  fstream file("18out.txt", ios::out);
  while(abs(x-xs)>0.00000001){
    xs=x;
    double y = 0.57/n;
    x = 2.8*sin(y)/(7*(1+y)*(4-(1+y)*(1+y))-21);
    n = n + 0.7;
    file.precision(15);
    file<<x<<' '<<abs(x-xs)<<endl;
  }
  cout<<x;
  return 0;
}
