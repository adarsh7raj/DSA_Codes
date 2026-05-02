
//memoization:

// User function Template for C++
// TC	O(n*n)
// SC	O(n)
class Solution {
  public:
  
int solve(int n,vector<int>&price,vector<int>&dp){
    if(n==0){
        return 0;
    }
    int maxi=0;
    if(dp[n]!=-1){
        return dp[n];
    }
    for(int cut=1;cut<=n;cut++){
        int profit=price[cut-1]+solve(n-cut,price,dp);
        maxi=max(maxi,profit);
    }
    return dp[n]= maxi;
}
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<int>dp(n+1,-1);
        return solve(n,price,dp);
        
    }
};

// another way to solve : 
//TC : O(n*n)
//SC : O(n*n) for dp array

class Solution {
public:

    int solve(int i,
              int len,
              vector<int>& price,
              vector<vector<int>>& dp) {

        // Base case
        if(len == 0) {
            return 0;
        }

        // No more cuts available
        if(i == price.size()) {
            return 0;
        }

        // Memoization
        if(dp[i][len] != -1) {
            return dp[i][len];
        }

        int take = 0;

        // Rod length corresponding to index i
        int rodLength = i + 1;

        // Take current rod piece
        if(rodLength <= len) {

            take =
                price[i] +
                solve(i,
                      len - rodLength,
                      price,
                      dp);
        }

        // Skip current rod piece
        int not_take =
            solve(i + 1,
                  len,
                  price,
                  dp);

        return dp[i][len] =
               max(take, not_take);
    }

    int cutRod(vector<int>& price) {

        int n = price.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        return solve(0, n, price, dp);
    }
};

// tabulation code:
// TC : O(n*n)
// SC : O(n) for dp array
class Solution {
public:

    int cutRod(vector<int>& price) {

        int n = price.size();

        vector<int> dp(n + 1, 0);

        // Build answer from smaller lengths
        for(int len = 1; len <= n; len++) {

            int maxi = 0;

            // Try every possible first cut
            for(int cut = 1; cut <= len; cut++) {

                int profit =
                    price[cut - 1] +
                    dp[len - cut];

                maxi = max(maxi, profit);
            }

            dp[len] = maxi;
        }

        return dp[n];
    }
};