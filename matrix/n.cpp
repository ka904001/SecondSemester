#include <iostream>
using namespace std;

int main(){
  int a[50][50]{0};
  for(int j = 50; j>=1; j--){
    int k = j;
    for(int i = 50; i>=1; i--){
      if(51-i<=j){
        a[i-1][j-1]=k;
        k++;
      }
    }
  }
  for(int i = 0; i<50; i++){
    for(int j = 0; j<50; j++){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  int sum = 0;
  for(int i = 0; i<50; i++){
    cout<<a[i][15]<<" ";
    sum+=a[i][15];
  }
  cout<<endl<<sum;
  return 0;
}
