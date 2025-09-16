// #include <iostream>
// using namespace std;

// int sum(int n){
//     int sum =0;
//     while(n>1){

//      int current_sum=n+n-1;
//      sum+=current_sum;
//      n-=2;
//     }

// return sum;
// }

// int main(){
//     int n;
//     cin>>n;
//    int result= sum(n);
//    if(n%2==1){
//     result
//    }
//    cout<<result;
// }

#include <iostream>
using namespace std;

int n_sum(int n) {
    if (n <= 1) {
        return n;  // Base case: return n itself when n is 1 or 0
    }
    return n + n_sum(n - 1);  // Add current value and recurse with (n-2)
}

int main() {
    int n;
    cin >> n;
    
    int result = n_sum(n);  // Compute sum using recursion
    cout << result << endl;

    return 0;  // Indicate successful execution
}
