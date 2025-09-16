#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the pattern: ";
    cin>>n;
    for(int i=1;i<=n;i++){

        for(int j=0;j<=2*n-1;j++){
            if(j>=i && j<=2*n-i){
                cout<<"*";
        }
        else{
            cout<<" ";
        }
        }
        cout<<endl;
    }
}