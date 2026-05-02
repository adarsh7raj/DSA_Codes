//memoization: time complexity is O(m*n) and space complexity is O(m*n)

// this will give TLE because of large constraints
// dp[i][j] = minimum path sum from (i,j) to last row
class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        int n = triangle.size();

        // base case → last row
        if (i == n - 1) return triangle[i][j];

        // already computed
        if (dp[i][j] != -1) return dp[i][j];

        int down = solve(triangle, i + 1, j, dp);
        int diag = solve(triangle, i + 1, j + 1, dp);

        return dp[i][j] = triangle[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // dp shape same as triangle
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(i + 1, -1);
        }

        return solve(triangle, 0, 0, dp);
    }
};
//tabulation: time complexity is O(m*n) and space complexity is O(m*n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(i+1, -1);  
        }

        dp[0][0]=triangle[0][0];
      for(int i=1;i<n;i++){
        dp[i][0]=triangle[i][0]+dp[i-1][0];
      }
      for(int i=1;i<n;i++){
        for(int j=1;j<triangle[i].size();j++){
            if(j==triangle[i].size()-1){
                dp[i][j]=triangle[i][j]+dp[i-1][j-1];
            }
            else{
    dp[i][j]=triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            }

            
        }
      }
     int mini=INT_MAX;

     for(int i=0;i<n;i++){
        mini=min(dp[n-1][i],mini);
     }
     return mini;
    }
};