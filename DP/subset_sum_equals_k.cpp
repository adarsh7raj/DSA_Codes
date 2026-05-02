

// optimal solution using DP : O(sum*k):
#include <bits/stdc++.h>
using namespace std;

bool find(int i, int sum, vector<int> &arr, vector<vector<int>> &dp) {
    if (sum == 0) return true;
    if (i == arr.size()) return false;

    if (dp[i][sum] != -1) return dp[i][sum];

    bool notPick = find(i + 1, sum, arr, dp);
    bool pick = false;
    if (arr[i] <= sum)
        pick = find(i + 1, sum - arr[i], arr, dp);

    return dp[i][sum] = pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return find(0, k, arr, dp);
}
// tabulation : O(n*k) and space complexity is O(n*k)

class Solution {
public:

    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // Sum 0 is always possible
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= sum; j++) {

                // not take
                bool not_take = dp[i-1][j];

                bool take = false;

                // take
                if(arr[i-1] <= j) {
                    take = dp[i-1][j - arr[i-1]];
                }

                dp[i][j] = take || not_take;
            }
        }

        return dp[n][sum];
    }
};