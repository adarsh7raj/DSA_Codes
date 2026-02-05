
//TC:O(nlog(log(n)))
class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<int>ans(n+1,1);
        vector<int>result;
        for(int i=2;i*i<=n;i++){
            
            if(ans[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    ans[j]=0;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(ans[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};