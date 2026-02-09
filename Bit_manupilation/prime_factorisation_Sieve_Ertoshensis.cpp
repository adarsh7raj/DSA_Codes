// in this approach we will use sieve of Ertoshensis to find smallest prime factor 
//of every number from 1 to n then we will keep dividing n by its smallest prime factor
// until n becomes 1

// User function Template for C++

class Solution {
  public:
  
    void sieve() {
        
       
    }

    vector<int> findPrimeFactors(int n) {

        // Write your code here
        vector<int>spf(n+1,1);
       
        for(int i=1;i<=n;i++){
            spf[i]=i;
        }
        
        for(int i=2;i*i<=n;i++){
            if(spf[i]==i){
                for(int j=i*i;j<=n;j+=i){
                    if(spf[j]==j){
                        spf[j]=i;
                    }
                }
            }
        }
        vector<int>ans;
        while(n!=1){
            ans.push_back(spf[n]);
            n/=spf[n];
        }
        return ans;
    }
};