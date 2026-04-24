

//optimal solution: 

class Solution {
public:
int solve(int i, vector<int>& heights, vector<int>& dp,int k) {
        int n = heights.size();

        // base case: already at last index
        if (i == n - 1) return 0;

        if (dp[i] != -1) return dp[i];
        int value=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i+j<n){
  value=min(value,abs(heights[i]-heights[i+j])+solve(i+j,heights,dp,k));
            }
    
        }
     

        return dp[i] = value;
    }

    int frogJump(vector<int>& heights, int k) {
   int n = heights.size();
        vector<int> dp(n+1, -1);
        return solve(0, heights, dp,k);
    }
};
