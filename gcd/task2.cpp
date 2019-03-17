#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int n;
  cin>>n;
  double summ = 0, x1, x2, y1, y2;
  cin>>x1>>y1>>x2>>y2;
  for(int i = 0; i<n-2; i++){
    summ+= x1*y2-x2*y1;
    x1=x2;
    y1=y2;
    cin>>x2>>y2;
  }
  cout<<setprecision(4)<<abs(summ)/2;
  return 0;
}
