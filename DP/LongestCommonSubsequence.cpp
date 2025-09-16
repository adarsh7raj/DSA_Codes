// if do not use memoization, the TC will be O(2^(n+m))
// using memoization TC: O(n*m) SC: O(n*m)

// top down approach
class Solution {
public:
    int dp[1001][1001]; // assuming max length of strings is <= 1000

    int solve(string &t1, string &t2, int i, int j) {
        if (i == t1.size() || j == t2.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (t1[i] == t2[j]) {
            return dp[i][j] = 1 + solve(t1, t2, i + 1, j + 1);
        } else {
            return dp[i][j] = max(
                solve(t1, t2, i + 1, j),
                solve(t1, t2, i, j + 1)
            );
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp)); // initialize all dp values to -1
        return solve(text1, text2, 0, 0);
    }
};


// bottom up approach


class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int m = t1.size();
        int n = t2.size();
        int dp[1001][1001]; // Assuming strings won't be longer than 1000

        // Initialize base cases
        for (int i = 0; i <= m; i++) dp[i][0] = 0;
        for (int j = 0; j <= n; j++) dp[0][j] = 0;

        // Build the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t1[i - 1] == t2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};
