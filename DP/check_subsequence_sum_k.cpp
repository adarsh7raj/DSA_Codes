// top down approach
// TC : O(n*k)
// SC : O(n*k) + O(n) for recursion stack
class Solution {
public:
    int dp[2000][2001];

    
bool isSubsequenceSumK(int index, int currentSum, vector<int>& arr, int K) {
    if (currentSum == K) return true;  // Found a subsequence
    if (index == arr.size()) return false;  // Reached end without sum

    if (dp[index][currentSum] != -1) return dp[index][currentSum];

    // Include current element
    bool include = false;
    if (currentSum + arr[index] <= K)
        include = isSubsequenceSumK(index + 1, currentSum + arr[index], arr, K);

    // Exclude current element
    bool exclude = isSubsequenceSumK(index + 1, currentSum, arr, K);

    return dp[index][currentSum] = include || exclude;
}

    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
      memset(dp,-1,sizeof(dp));
        return isSubsequenceSumK(0, 0, arr, k);
    }
};
// bottom up approach
// TC : O(n*k)
// SC : O(n*k)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int K) {
        vector<vector<bool>> dp(n + 1, vector<bool>(K + 1, false));

        // Base case: sum = 0 is always possible
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= K; j++) {
                bool take = false;
                if (arr[i - 1] <= j){
                     take = dp[i - 1][j - arr[i - 1]];// we have taken the element than we have to check for remaining sum i.e j-arr[i-1]
                   
                }
                   
                    bool notTake = dp[i - 1][j];// we have not taken the element than we have to check for same sum j
                    dp[i][j] = take || notTake;
            }
        }

        return dp[n][K];
    }
};

int main() {
    vector<int> arr = {1, 2, 3};
    int K = 5;
    Solution s;
    cout << (s.checkSubsequenceSum(arr.size(), arr, K) ? "Yes" : "No");
    return 0;
}

// space optimized bottom up approach
//TC : O(n*k)
//SC : O(k)


Think of them as compressed versions of dp[i-1] and dp[i].

    // 2D DP meaning	Space-optimized equivalent
    // dp[i-1][j]=prev[j]
    // dp[i][j]	=curr[j]
#include <bits/stdc++.h>
using namespace std;

bool checkSubsequenceSum(int n, vector<int>& arr, int K) {
    vector<bool> prev(K + 1, false), curr(K + 1, false);

    // Base case
    prev[0] = true; // sum 0 is always possible

    for (int i = 1; i <= n; i++) {
        curr[0] = true;
        for (int j = 1; j <= K; j++) {
            bool notTake = prev[j];
            bool take = false;
            if (arr[i - 1] <= j)
                take = prev[j - arr[i - 1]];
            curr[j] = take || notTake;
        }
        prev = curr;
    }

    return prev[K];
}

int main() {
    vector<int> arr = {2, 3, 5};
    int K = 5;
    cout << (checkSubsequenceSum(arr.size(), arr, K) ? "Yes" : "No");
}
