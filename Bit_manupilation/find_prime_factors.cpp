

// brute force approach
//TC: O(n*n)
class Solution {
  public:
  bool isPrime(int n){
      for(int i=2;i<n;i++){
          if(n%i==0){
              return false;
          }
      }
      return true;
  }
    vector<int> primeFac(int n) {
        // code here
        vector<int>ans;
      //  int range=pow(n,0.5);
     if( isPrime(n)){
         
         return {n};
     }
        for(int i=2;i<n;i++){
            if(n%i==0 && isPrime(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};


// better approach
//TC: O(sqrt(n)*log(n)) for not prime number and O(n*log(n)) for prime number
class Solution {
  public:

    vector<int> primeFac(int n) {
        // code here
        vector<int>ans;
      //  int range=pow(n,0.5);
    
        for(int i=2;i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                while(n%i==0){
                    n=n/i;
                }
            }
        }
        return ans;
    }
};

// optimal approach

//TC: O(sqrt(n) *logn)
class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        vector<int>ans;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                while(n%i==0){
                    n=n/i;
                }
            }
        }
        if(n>1){
            ans.push_back(n);
        }
        return ans;
    }
};


