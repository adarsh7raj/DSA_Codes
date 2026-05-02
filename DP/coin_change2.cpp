

// memoization code:

class Solution {
public:
int solve(int i,vector<int>&coins,int amount,vector<vector<int>>&dp){

    if(i==coins.size()){
        if(amount==0){
            return 1;
        }
        return 0;
    }
    if(dp[i][amount]!=-1){
        return dp[i][amount];
    }
    int take=0;
    if(coins[i]<=amount){
    take=solve(i,coins,amount-coins[i],dp);
    }
   
    int not_take=solve(i+1,coins,amount,dp);
    return dp[i][amount]= take+not_take;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
          return solve(0,coins,amount,dp);
    }
};

// tabulation code:

