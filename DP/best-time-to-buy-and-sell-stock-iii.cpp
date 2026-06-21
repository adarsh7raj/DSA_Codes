

class Solution {
public:
int solve(int i,int buy,vector<int>&prices,int count,vector<vector<vector<int>>>&dp){
  if(count<0 ||i>=prices.size()){
    return 0;
  }
if(dp[i][buy][count]!=-1){
    return dp[i][buy][count];
}
  if(buy){

    return dp[i][buy][count]= max(-prices[i]+solve(i+1,0,prices,count-1,dp),solve(i+1,1,prices,count,dp));
  }
  return dp[i][buy][count]= max(prices[i]+solve(i+1,1,prices,count,dp),solve(i+1,0,prices,count,dp));

}
    int maxProfit(vector<int>& prices) {
        int count=2;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

        return solve(0,1,prices,count,dp);
    }
};

//space optimized

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int i = prices.size() - 1; i >= 0; i--) {

            for(int buy = 0; buy <= 1; buy++) {

                for(int cap = 1; cap <= 2; cap++) {

                    if(buy) {
                        curr[buy][cap] =
                            max(
                                -prices[i] + ahead[0][cap],
                                ahead[1][cap]
                            );
                    }
                    else {
                        curr[buy][cap] =
                            max(
                                prices[i] + ahead[1][cap - 1],
                                ahead[0][cap]
                            );
                    }
                }
            }

            ahead = curr;
        }

        return ahead[1][2];
    }
};