#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void funct(vector<int> &am, int t, int j){
  if(t==0){return ;}
  else{
    for(; j <= t; j++){
      if(t%j==0){
        am[j]++;
        cout<<"hey\n";
        funct(am, t/j, j);
        return;
      }
    }
    return;
  }
}
int nok(int a, int b, int c){
  vector<int> am(1001, 0), bm(1001, 0), cm(1001, 0);
  am[1]=1;
  bm[1]=1;
  cm[1]=1;
  funct(am, a, 2);
  funct(bm, b, 2);
  funct(cm, c, 2);
  int nok = 1;
  for(int i = 1; i < 1001; i++){
    if(am[i]!=0||bm[i]!=0||cm[i]!=0){
      int max = am[i]>bm[i]?am[i]>cm[i]?am[i]:cm[i]:bm[i]>cm[i]?bm[i]:cm[i];
      nok = nok*pow(i, max);
    }
  }
  return nok;
}
int nok(int a, int b){
  vector<int> am(1001, 0), bm(1001, 0);
  am[1]=1;
  bm[1]=1;
  funct(am, a, 2);
  funct(bm, b, 2);
  int nok = 1;
  for(int i = 1; i < 1001; i++){
    if(am[i]!=0||bm[i]!=0){
      int max = am[i]>bm[i]?am[i]:bm[i];
      nok = nok*pow(i, max);
    }
  }
  return nok;
}
int main(){
  int a, b, c;
  cin>>a>>b>>c;
  cout<<nok(a, b, c)*a*b*c/nok(nok(a,b), c);
  return 0;
}
