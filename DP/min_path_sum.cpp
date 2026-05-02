
// memoization: time complexity is O(m*n) and space complexity is O(m*n)+O(m+n) for recursion stack
class Solution {
public:

int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){

    int m=grid.size();
    int n=grid[0].size();

    if(i>=m || j>=n){
        return INT_MAX;
    }
    if(i==m-1 && j==n-1){
        return grid[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
     int sum=min(solve(grid,i+1,j,dp),solve(grid,i,j+1,dp));
     
     return dp[i][j]=grid[i][j]+sum;

     
} 
     
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return solve(grid,0,0,dp);
    }
};

// tabulation: time complexity is O(m*n) and space complexity is O(m*n)

class Solution {
public:

int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){

    int m=grid.size();
    int n=grid[0].size();

    if(i>=m || j>=n){
        return INT_MAX;
    }
    if(i==m-1 && j==n-1){
        return grid[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
     int sum=min(solve(grid,i+1,j,dp),solve(grid,i,j+1,dp));
     
     return dp[i][j]=grid[i][j]+sum;

     
} 
     
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];

        }
        for(int j=1;j<n;j++){
            dp[0][j]=grid[0][j]+dp[0][j-1];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};