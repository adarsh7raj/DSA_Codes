// #include <iostream>
// using namespace std;
//  void print_number(int n,int i){
    
//     if(i<=n){
// cout<<i << endl;

//   print_number(n,i+1);
//     }
// }
// int main(){
//     print_number(5,1);
// }

#include <iostream>
using namespace std;

void print_number(int n){
    if(n>0){
        
        cout <<n <<endl;
        print_number(n-1);
    }
}
int main(){
    print_number(5);
}