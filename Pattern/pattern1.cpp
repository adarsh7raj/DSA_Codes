#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the pattern: ";
    cin>>n;
    for(int i=1;i<=(n+1)/2;i++){
        for(int j=1;j<=n;j++){
            if(j>=n-i+1 && j<=n+i-1){
             
            if((i+j)%2==0){
                cout<<"*";
            }
            else{
                cout<<" ";
            
            }
            
        }
        else{
            cout<<" ";
        }
        }
        cout<<endl;
    }
    
}

