

// brute force approach this will give tle : 


class Solution {
  public:
  
  int solve(int prev,int curr,int n ,vector<int>&dp,int cost,vector<int>&height){
      
      if(curr>=n){
          return INT_MAX;
      }
      if(curr==n-1){
          cost+=abs(height[curr]-height[prev]);
          return cost;
      }
      cost+=abs(height[curr]-height[prev]);
      return min(solve(curr,curr+1,n,dp,cost,height),solve(curr,curr+2,n,dp,cost,height));
  }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n+1,-1);
        return solve(0,0,n,dp,0,height);
    }
};


// optimized solution with memoization
// here dp signifies  dp[i] = minimum cost required to reach the LAST index starting from index i
class Solution {
public:
    int solve(int i, vector<int>& height, vector<int>& dp) {
        int n = height.size();

        // base case: already at last index
        if (i == n - 1) return 0;

        if (dp[i] != -1) return dp[i];

        int jump1 = abs(height[i] - height[i + 1]) +
                    solve(i + 1, height, dp);

        int jump2 = INT_MAX;
        if (i + 2 < n) {
            jump2 = abs(height[i] - height[i + 2]) +
                    solve(i + 2, height, dp);
        }

        return dp[i] = min(jump1, jump2);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(0, height, dp);
    }
};