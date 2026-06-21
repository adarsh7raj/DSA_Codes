
//  memoization code :
//  here dp[i][j][count] stores the answer obtained starting from:

// index i in text1
// index j in text2
// with current matching substring length = count
class Solution {
  public:
  
int ans = 0;

int solve(int i,
          int j,
          string &text1,
          string &text2,
          vector<vector<int>>& dp) {

    if(i == text1.size() || j == text2.size()) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // explore all states
    

    // matching case
    if(text1[i] == text2[j]) {

        dp[i][j] =
            1 + solve(i+1, j+1, text1, text2, dp);

        ans = max(ans, dp[i][j]);
    }
    else {

        dp[i][j] = 0;
    }
    solve(i+1, j, text1, text2, dp);
    solve(i, j+1, text1, text2, dp);

    return dp[i][j];
}
    int longCommSubstr(string& s1, string& s2) {
        // code here
       int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    solve(0, 0, s1, s2, dp);

    return ans;
      
        }
       
    
};


// tabulation code :

class Solution {
public:

    int longestCommonSubstring(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        int dp[n+1][m+1];

        // initialize base cases
        for(int i=0; i<=n; i++) {
            dp[i][0] = 0;
        }

        for(int j=0; j<=m; j++) {
            dp[0][j] = 0;
        }

        int ans = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {

                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }
};