
// memoization method TC: O(n1*n2) SC: O(n1*n2)+O(n1+n2)

class Solution {
public:
    int solve(int i , int j,vector<vector<int>>&dp,string word1,string word2){
        if(i>=word1.size()){
            return word2.size()-j;
        }
        if(j>=word2.size()){
            return word1.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j] =solve(i+1,j+1,dp,word1,word2);
        }
        return dp[i][j]= 1+min(solve(i+1,j,dp,word1,word2),solve(i,j+1,dp,word1,word2));
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(0,0,dp,word1,word2);
    }
};