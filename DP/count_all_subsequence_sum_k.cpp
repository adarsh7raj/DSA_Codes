// without using memoization

class Solution {
public:
    int solve(int i, int k, vector<int>& nums) {
        // Base cases
        if (k == 0) return 1;          // Found one valid subsequence
        if (i == nums.size()) return 0; // No more elements left

        int notTake = solve(i + 1, k, nums);
        int take = 0;
        if (nums[i] <= k)
            take = solve(i + 1, k - nums[i], nums);

        return take + notTake;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        return solve(0, k, nums);
    }
};

// using memoization

class Solution {
public:
    int solve(int i, int k, vector<int>& nums, vector<vector<int>>& dp) {
        // Base cases
        if (k == 0) return 1;        // Found a valid subsequence
        if (i == nums.size()) return 0; // Reached end without making sum

        if (dp[i][k] != -1) return dp[i][k];

        int notTake = solve(i + 1, k, nums, dp);
        int take = 0;
        if (nums[i] <= k)
            take = solve(i + 1, k - nums[i], nums, dp);

        return dp[i][k] = take + notTake;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(k + 1, -1));
        return solve(0, k, nums, dp);
    }
};


// using tabulation

class Solution {
public:
    int countSubsequenceWithTargetSum(vector<int>& nums, int K) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(K + 1, 0));

        // Base case: sum = 0 -> 1 subsequence (empty subsequence)
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int sum = 0; sum <= K; sum++) {
                int notTake = dp[i-1][sum];  // exclude current element
                int take = 0;                 
                if (nums[i-1] <= sum)
                    take = dp[i-1][sum - nums[i-1]]; // include current element

                dp[i][sum] = take + notTake;
            }
        }

        return dp[n][K];
    }
};
//Why the inner loop still starts at 0

// Even though dp[i][0] is initialized, the DP recurrence is:

// dp[i][sum] = dp[i-1][sum] + (nums[i-1] <= sum ? dp[i-1][sum - nums[i-1]] : 0);


// dp[i-1][sum] → ways to make sum sum without including the i-th element

// dp[i-1][sum - nums[i-1]] → ways to make sum sum by including the i-th element

// If we start the loop from sum = 1, we skip updating dp[i][0] using the recurrence:

// Example: if nums[i-1] = 0, including it can create additional subsequences that sum to 0 (e.g., [0]).

// Or in general, you want all sums from 0 to K to be updated in a uniform way so that the table is correctly filled.

// 💡 In short:

// The initialization handles the base case, but the recurrence can still affect dp[i][0] if you include elements like 0.
// Starting from 0 ensures all sums, including 0, are correctly propagated through the DP table.// thus we start from 0 to K in inner loop