
// User function Template for C++

class Solution {
  public:
  int calculate_xor(int n){
      if(n%4==0){
          return n;
      }
      else if(n%4==1){
          return 1;
      }
      else if(n%4==2){
          return n+1;
      }
      else if(n%4==3){
          return 0;
      }
      return 0;
  }
    int findXOR(int l, int r) {
        // complete the function here
      return calculate_xor(l-1)^calculate_xor(r);
          
    }
};