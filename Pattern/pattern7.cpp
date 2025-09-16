#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the pattern: ";
    cin>>n;
    int k=0;
    for(int i=1;i<=n;i++){
  // if n is even
  if(n%2==0){
            if(i<=n/2){
                k++;
            }
           if(i>n/2+1){
            k--;
           }
        }
        // if n is odd
else{
       if(i<=(n+1)/2){
            k++;
        }
        else{
            k--;
        }
}
 

        for(int j=1;j<=(n+1)/2;j++){
            if(j<=k){
             
            cout<<"*";
            
        }
        else{
            cout<<" ";
        }
        }
        cout<<endl;
    }
    
}

