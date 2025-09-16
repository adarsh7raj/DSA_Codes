
// Egg Drop Problem - Top Down Approach
// TC: O(k * n^2) SC: O(k * n)
// this will give TLE: Time Limit Exceeded for large inputs
class Solution {
public:
    // dp[k][n] stores result for k eggs and n floors
    vector<vector<int>> dp;

    int solve(int k, int n) {
        // base cases
        if (n == 0 || n == 1) return n;
        if (k == 1) return n;

        // already solved
        if (dp[k][n] != -1) return dp[k][n];

        int ans = INT_MAX;

        // try dropping from every floor
        for (int f = 1; f <= n; f++) {
            int breaks = solve(k-1, f-1);    // egg breaks
            int notBreaks = solve(k, n-f);   // egg doesn't break
            int worst = 1 + max(breaks, notBreaks);  // here maximum is taken because we want the worst case scenario
            ans = min(ans, worst);
        }

        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        dp.assign(k+1, vector<int>(n+1, -1));
        return solve(k, n);
    }
};


// Egg Drop Problem - Bottom Up Approach
// TC: O(k * n^2) SC: O(k * n)