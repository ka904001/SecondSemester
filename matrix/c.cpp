#include <iostream>
#include <fstream>
using namespace std;

bool eq(int a[6], int b[6]){
  if(a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3]&&a[4]==b[4]&&a[5]==b[5]) return 1;
  return 0;
}

int main(){
  int a[6]{0,3,1,3,4,5}, b[6]{0,3,6,6,4,7}, c[6]{0,2,0,0,0,7};
  fstream file("out.txt", ios::out);
  while(!eq(a,c)){
    int j = 1, i = 0;
    while(j==1&&i<6){
      i++;
      a[i]++;
      if(a[i]<=b[i]){
        j=0;
      } else{
        a[i] = 0;
      }
    }
    for(auto i:a){
      file<<i<<' ';
    }
    file<<endl;
  }
  cout<<"end";
  return 0;
}
