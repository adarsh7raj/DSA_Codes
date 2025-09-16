
// TC will be O(n*m) and SC will be O(n*m) + O(n) due to stack space if we use memoization
// if we do not use memoization, the TC will be O(2^(n+m
class Solution {
public:
int dp[501][501];
int  solve(string s1, string s2,int i, int j){
    if(i==s1.size()){
        return s2.size()-j;
    }
    else if(j==s2.size()){
        return s1.size()-i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=solve(s1,s2,i+1,j+1);

    }
    else{
        int  insertN=1+solve(s1,s2,i,j+1);
        int  removeN=1+solve(s1,s2,i+1,j);
        int  replaceN=1+solve(s1,s2,i+1,j+1);
         return dp[i][j]=min({insertN,removeN,replaceN});
    }
    return -1;
 
}
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0);
        
    }
};

// Bottom-up approach

class Solution {
public:

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    // Create DP table of size (n+1) x (m+1)
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    // Base Cases
    for(int i = 0; i <= n; ++i) dp[i][0] = i;       // Convert i chars to empty: i deletions
    for(int j = 0; j <= m; ++j) dp[0][j] = j;       // Convert empty to j chars: j insertions

    // Bottom-up DP
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(word1[i-1] == word2[j-1]){
                // Characters match, no operation
                dp[i][j] = dp[i-1][j-1];
            } else {
                // Choose the minimum of insert, delete, replace
                dp[i][j] = 1 + min({
                    dp[i-1][j],    // delete
                    dp[i][j-1],    // insert
                    dp[i-1][j-1]   // replace
                });
            }
        }
    }

    return dp[n][m];
}



};