#include <iostream>
using namespace std;

int main(){
  int a[10][10], b[10][10]{0};
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      a[i][j] = i*10+j+1;
    }
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cout.width(2);
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      b[i][j] = a[i][j];
    }
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      a[i][j]=b[j][10-1-j];
    }
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){

    }
  }
  cout<<"------------------------"<<endl;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cout.width(2);
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      b[i][j]=a[i][j];
    }
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      a[i][j] = b[j][i];
    }
  }
  cout<<"------------------------"<<endl;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cout.width(2);
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      b[i][j]=a[i][j];
    }
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      a[i][j] = b[10-1-i][j];
    }
  }
  cout<<"------------------------"<<endl;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cout.width(2);
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"***********************"<<endl;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      a[i][j] = i*10+j+1;
    }
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cout.width(2);
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      b[i][j] = a[i][j];
    }
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      a[i][j]=b[9-j][i];
    }
  }
  cout<<"------------------------"<<endl;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cout.width(2);
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
