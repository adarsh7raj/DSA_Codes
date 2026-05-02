
// memoized code using offset trick
class Solution {
public:

    int solve(int i,
              int target,
              int curr_sum,
              vector<int>& nums,
              vector<vector<int>>& dp) {

        // Base case
        if(i == nums.size()) {

            if(target==curr_sum){
                return 1;
            }
            return 0;
        }

        int offset = 1000;

        // Memoization
        if(dp[i][curr_sum + offset] != -1) {

            return dp[i][curr_sum + offset];
        }

        // Put '+' sign
        int positive =
            solve(i + 1,
                  target,
                  curr_sum + nums[i],
                  nums,
                  dp);

        // Put '-' sign
        int negative =
            solve(i + 1,
                  target,
                  curr_sum - nums[i],
                  nums,
                  dp);

        return dp[i][curr_sum + offset] =
               positive + negative;
    }

    int findTargetSumWays(vector<int>& nums,
                          int target) {

        int n = nums.size();

        // Range:
        // -1000 to +1000
        vector<vector<int>> dp(
            n,
            vector<int>(2001, -1)
        );

        return solve(0,
                     target,
                     0,
                     nums,
                     dp);
    }
};
// we can also it using unordered_map for memoization instead of 2D vector

// using tabulation
class Solution {
public:

    int findTargetSumWays(vector<int>& nums,
                          int target) {

        int n = nums.size();

        int offset = 1000;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(2001, 0)
        );

        dp[0][offset] = 1;

        for(int i = 1; i <= n; i++) {

            for(int sum = -1000;
                sum <= 1000;
                sum++) {

                int ways = 0;

                // sum - nums[i-1]
                if(sum - nums[i-1] >= -1000 &&
                   sum - nums[i-1] <= 1000) {

                    ways += dp[i-1]
                              [sum - nums[i-1] + offset];
                }

                // sum + nums[i-1]
                if(sum + nums[i-1] >= -1000 &&
                   sum + nums[i-1] <= 1000) {

                    ways += dp[i-1]
                              [sum + nums[i-1] + offset];
                }

                dp[i][sum + offset] = ways;
            }
        }

        return dp[n][target + offset];
    }
};