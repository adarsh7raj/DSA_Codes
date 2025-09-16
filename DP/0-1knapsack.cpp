
//TC will be O(n*m) and SC will be O(n*m) + O(n) due to stack space if we use memoization
// if we do not use memoization, the TC will be O(2^(n+m
class Solution {
  public:
  vector<vector<int>>dp;
  int solve(int w,int i,vector<int>&val,vector<int>&wt){
      if(w<=0 || i>=wt.size()){
          return 0;
          
      }
      if(dp[i][w]!=-1){
          return dp[i][w];
      }
      int take=0;
      if(wt[i]<=w){
         
         
          take= val[i]+solve(w-wt[i],i+1,val,wt);
      }
      int not_take=solve(w,i+1,val,wt);
      return dp[i][w]=max(take,not_take);
      
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
       dp = vector<vector<int>>(wt.size(), vector<int>(W + 1, -1));
       return solve(W,0,val,wt);
    }
};


// bottom up approach

#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // i from 1 to n for 1-based dp
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            int take = 0;
            if (wt[i - 1] <= w) {
                take = val[i - 1] + dp[i - 1][w - wt[i - 1]];
            }
            int notTake = dp[i - 1][w];

            dp[i][w] = max(take, notTake);
        }
    }

    return dp[n][W];
}



// Space optimized version

int knapsack(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            int take = 0;
            if (wt[i - 1] <= w) {
                take = val[i - 1] + prev[w - wt[i - 1]];
            }
            int notTake = prev[w];

            curr[w] = max(take, notTake);
        }
        prev = curr; // move to next item
    }

    return prev[W];
}

// Interpretation of [0, 3, 3, 3, 3]:
// Each index i in the array represents the maximum value you can get with total weight capacity i after considering all items.

// So, here's what each element means:

// prev[0] = 0: With weight 0, you can't pick anything, so value is 0.

// prev[1] = 3: Max value with weight capacity 1 is 3 (only item 3 with weight 1 and value 3 fits).

// prev[2] = 3: Still only item 3 fits, total value is 3.

// prev[3] = 3: Still only item 3 fits, total value is 3.

// prev[4] = 3: Item 1 (weight 4, value 1) also fits, but it gives only value 1. So the optimal choice is still item 3, giving value 3.

// Summary:
// The array signifies the optimal value we can get for every weight capacity from 0 to 4 using the given items. The final answer to the knapsack problem is prev[W] = prev[4] = 3.

















// Space optimized version using single array

int knapsack(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }

    return dp[W];
}