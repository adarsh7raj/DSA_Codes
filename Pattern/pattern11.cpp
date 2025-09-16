

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    int n;
    cout<<"Enter value of n: ";
    
    cin>>n;
    if(n<3 || n%2==0){
        cout<<"Value of n is invalid ";
        return 0;
    }
  for(int i=1;i<=(n+1)/2-1;i++){
      cout<<" ";
  }
   for(int i=1;i<=(n+1)/2;i++){
       for(int j=1;j<=n;j++){
           if(j>=(n+1)/2+1-i && j<=(n+1)/2-1+i){
               cout<<"*";
           }
           else{
               cout<<" ";
           }
       }
       cout<<endl;
       
   for(int i=1;i<=(n+1)/2-1;i++){
      cout<<" ";
  }
   }

   for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           if(j==(n+1)/2){
               cout<<"e";
           }
           else{
               cout<<" ";
           }
       }
      
       cout<<endl;
         for(int i=1;i<=(n+1)/2-1;i++){
      cout<<" ";
  }
   }
    
   for(int i=1;i<=n+2;i++){
       cout<<"*";
   }
   cout<<endl;
     for(int i=1;i<=(n+1)/2-1;i++){
      cout<<" ";
  }
   for(int i=1;i<=n;i++){
       for(int j=1;j<=n+2;j++){
           if(j==1 || j==n+2){
               cout<<"e";
           }
           else{
               cout<<" ";
           }
       }
       cout<<endl;
       if(i!=n){
                  for(int i=1;i<=(n+1)/2-1;i++){
                  cout<<" ";
  }
       }
  
   }
 
   for(int i=1;i<=(n+1)/2;i++){
       for(int j=1;j<=2*n+1;j++){
           if((j>=i && j<=n+1-i) ||( n+1+i<=j && j<=2*n+2-i)){
               cout<<"*";
           }
           else{
               cout<<" ";
           }
       }
       cout<<endl;
   }

    return 0;
}