class Solution {
public:

int solve(int steps,int n,vector<int>&dp){
    
    if(steps==n){
        return dp[steps]=1;  // it is optional to store this value in dp as it is not used again but we can do it for consistency
    }
    if(steps>n){
        return dp[steps]=0; // it is optional to store this value in dp as it is not used again but we can do it for consistency
    }
     if(dp[steps]!=-1){
        return dp[steps];
     }
    int ways=0;
    ways+=solve(steps+1,n,dp);
    ways+=solve(steps+2,n,dp);
    return dp[steps]=ways;
}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
     return solve(0,n,dp);
    }
};




// optimized solution with O(1) space complexity
int climbStairs(int n) {
    if (n <= 2) return n;

    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}