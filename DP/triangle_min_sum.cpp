

//memoization:
// this will give TLE because of large constraints
// dp[i][j] = minimum path sum from (i,j) to last row
class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp, int m) {

        if (i == m-1) return triangle[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int down = solve(triangle, i+1, j, dp, m);
        int diag = solve(triangle, i+1, j+1, dp, m);

        return dp[i][j] = triangle[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(i+1, -1);
        }

        return solve(triangle, 0, 0, dp, n);
    }
};

// tabulation: time complexity is O(m*n) and space complexity is O(m*n)

//dp