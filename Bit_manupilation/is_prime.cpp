
//TC:O(sqrt(n))
class Solution {
  public:
    bool isPrime(int n) {
        // code here
        if(n==1){
            return false;
        }
        int range=pow(n,0.5);
        for(int i=2;i<=range;i++){
            
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
};
