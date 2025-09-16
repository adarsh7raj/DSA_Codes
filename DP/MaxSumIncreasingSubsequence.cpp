

class Solution {
  public:
  int dp[1001][1001];
   int solve(vector<int>& arr, int i, int pv) {
         if(i >= arr.size()) {
            return 0;
        }

        if(pv != -1 && dp[i][pv] != -1) { // pv is  previous greatest element index
            return dp[i][pv];
        }


        int take = 0;
        if(pv == -1 || arr[i] > arr[pv]) {
            take = arr[i] + solve(arr, i + 1, i);
        }

        int not_take = solve(arr, i + 1, pv);
        
        if(pv != -1) {
            dp[i][pv] = max(take, not_take);
        }

        return max(take, not_take);
    }
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        memset(dp,-1,sizeof(dp));
      return   solve(arr,0,-1);
    }
};

// bottom up approach

#include <bits/stdc++.h>
using namespace std;

int maxSumIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp = arr;  // Initialize with the values themselves

    int maxSum = arr[0];

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {1, 101, 2, 3, 100, 4, 5};
    cout << "Maximum Sum of Increasing Subsequence: " << maxSumIncreasingSubsequence(arr) << endl;
    return 0;
}
