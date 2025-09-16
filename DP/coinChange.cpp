
// TC: O(n * amount)
// SC: O(n * amount) + O(n) for recursion stack

class Solution {
public:
int dp[12][10001];
    int solve(vector<int>& coins, int amount, int i) {
        if (amount == 0) return 0; // no coins needed
        if (i >= coins.size()) return INT_MAX - 1; // large number to avoid overflow
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        // If current coin is greater than amount, skip it
        if (coins[i] > amount) 
            return dp[i][amount]=solve(coins, amount, i + 1);

        // Take the coin
        int take = 1 + solve(coins, amount - coins[i], i);

        // Skip the coin
        int not_take = solve(coins, amount, i + 1);

        return dp[i][amount]=min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(coins, amount, 0);
        return (ans >= INT_MAX - 1) ? -1 : ans;
    }
};


// bottom-up DP




class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // dp[i][j] = min coins needed to make amount j using coins[0..i]
        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX - 1));

        // Base case: 0 coins needed to make amount 0
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }

       // Initialize first row (only using coins[0])
        for (int j = 1; j <= amount; j++) {
            if (j % coins[0] == 0) dp[0][j] = j / coins[0];
            else dp[0][j] = INT_MAX - 1;
        }

        // Fill the table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] <= j) {
                    dp[i][j] = min(1 + dp[i][j - coins[i]], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (dp[n - 1][amount] >= INT_MAX - 1) ? -1 : dp[n - 1][amount];
    }
};