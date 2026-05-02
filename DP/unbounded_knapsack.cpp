
// memoization approach
int solve(int i,int w,int n,vector<int>&profit,vector<int>&weight,vector<vector<int>>&dp){
    if(i==n || w<0){
        return 0;
    }
    if(w==0){
        return 0;
    }
  if(dp[i][w]!=-1){
      return dp[i][w];
  }
    int take=0;
    if(w>=weight[i]){
        take=profit[i]+solve(i,w-weight[i],n,profit,weight,dp);
    }
    int not_take=solve(i+1,w,n,profit,weight,dp);
    return dp[i][w]= max(take,not_take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return solve(0,w,n,profit,weight,dp);
}