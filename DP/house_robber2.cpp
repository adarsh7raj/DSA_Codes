


class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        int n = nums.size();

        if (i >= n) return 0;

        if (dp[i] != -1) return dp[i];

        int take = nums[i] + solve(nums, i + 2, dp);
        int not_take = solve(nums, i + 1, dp);

        return dp[i] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        // Case 1: exclude last
        vector<int> temp1(nums.begin(), nums.end() - 1);
        vector<int> dp1(n, -1);
        int case1 = solve(temp1, 0, dp1);

        // Case 2: exclude first
        vector<int> temp2(nums.begin() + 1, nums.end());
        vector<int> dp2(n, -1);
        int case2 = solve(temp2, 0, dp2);

        return max(case1, case2);
    }
};