// memoization : time complexity is O(m*n) and space complexity is O(m*n)+O(m+n) for recursion stack
class Solution {
public:

int dfs(vector<vector<int>>&obstacleGrid, vector<vector<int>>&dp,int i ,int j){
 int m=obstacleGrid.size();
 int n=obstacleGrid[0].size();
    if(i>=m || j>=n || obstacleGrid[i][j]==1){
        return 0;
    }
    if(i==m-1 && j==n-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
   return dp[i][j]=dfs(obstacleGrid,dp,i+1,j)+dfs(obstacleGrid,dp,i,j+1);
    
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m=obstacleGrid.size();
       int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n,-1));
        return dfs(obstacleGrid,dp,0,0);
    }
};


// optimal tabulation : time complexity is O(m*n) and space complexity is O(m*n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 1) return 0;

        // first column
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) break;
            dp[i][0] = 1;
        }

        // first row
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) break;
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[m-1][n-1];
    }
};