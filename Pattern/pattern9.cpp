#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the pattern: ";
    cin>>n;
    for(int i=1;i<=n;i++){
  for(int j=1;j<=n;j++){
      if(j==n-i+1){
        cout<<"/";
    }
   else if(j==i ){
        cout<<"\\";
    }
   
    else{
        cout<<"*";
    }
  }
  cout<<endl;
    }
}
