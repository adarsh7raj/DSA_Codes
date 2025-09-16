#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the pattern: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int k=1;
        for(int j=1;j<=2*n-1;j++){
            if(j>=n-i+1 && j<=n+i-1){
             
            cout<<k;
            if(j<n){
                k++;
            }
            else{
                k--;
            }
            
        }
        else{
            cout<<" ";
        }
        }
        cout<<endl;
    }
    
}

