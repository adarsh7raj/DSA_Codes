
// bottom up approach
//TC: O(n*m) SC: O(n*m)

class Solution {
public:


    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        
        for(int i=0;i<n;i++){
            
            dp[i][m]=false;
        }
     dp[n][m]=true;
      for(int j=m-1;j>=0;j--){
        if(p[j]=='*'){
            dp[n][j]=dp[n][j+1];
        }
        else{
            dp[n][j]=false;
        }
      }
         for(int i=n-1;i>=0;i--){

            for(int j=m-1;j>=0;j--){

                if(s[i]==p[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
               else if(p[j]=='?'){
                    dp[i][j]=dp[i+1][j+1];
                }
                else if(p[j]=='*'){
                    dp[i][j]=dp[i][j+1]|| dp[i+1][j];
                }
                else{
                    dp[i][j]=false;
                }
            }
         }
        return dp[0][0];
    }
};