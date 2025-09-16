/**************************************************************** C++ ****************************************************************/
//T.C : O(m*n)
//S.C : O(m*n)
//Approach-1 (Recursion + Memoization)

// In this code, t[m][n] represents the length of the Longest Common Subsequence (LCS) between the first m characters of s1 and the first n characters of s2
class Solution {
public:
    int t[1001][1001];
    int LCS(string& s1, string& s2, int m, int n) {
        if(m == 0 || n == 0)
            return t[m][n] = 0;
        
        if(t[m][n] != -1)
            return t[m][n];
        
        if(s1[m-1] == s2[n-1])
            return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        
        return t[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        memset(t, -1, sizeof(t));
        
        return LCS(text1, text2, m, n);
    }
};

// Approach 1.2 top down memoization
//In this top-down memoized code, dp[i][j] stores the length of the LCS of the substrings starting at indices
// i in s1 and j in s2.

// For example, if s1 = "abc" and s2 = "ac", then:

// i	j	Substrings considered	dp[i][j]
// 0	0	s1[0..] = "abc", s2[0..] = "ac"	2 (LCS = "ac")
// 1	1	s1[1..] = "bc", s2[1..] = "c"	1 (LCS = "c")
// 2	1	s1[2..] = "c", s2[1..] = "c"	1 (LCS = "c")

class Solution {
public:
int dp[1001][1001];
int solve(string &s1,string &s2,int i,int j){
    int n=s1.size();
    int m=s2.size();
    if(i>=n || j>=m){
        return 0;

    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j] =1+ solve(s1,s2,i+1,j+1);
    }
    else{
        return dp[i][j] = max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
    }
    return -1;
}
    int longestCommonSubsequence(string t1, string t2) {
        memset(dp,-1,sizeof(dp));
        return solve(t1,t2,0,0);
    }
};


//Approach-2 (Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)

//t[i][j] represents the length of the Longest Common Subsequence (LCS) between the first i characters of text1
// and the first j characters of text2.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> t(m+1, vector<int>(n+1));

//in t[i][j] if any of i or j is 0 then the lcs will be 0 because if any string is empty then lcs will be 0
//that is why we are initializing first row and first column with 0

        for(int i=0;i<=m;i++){
            t[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            t[0][j]=0;
        }
        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
               
                 if(text1[i-1] == text2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
        
        return t[m][n];
    }
};





//Approach-3 (Bottom Up space optmized)
/*
Since, in bottm up approach, we are using results of only two rows, t[i] and t[i-1]. So, we can take only two rows.
*/
//T.C : O(m*n)
//S.C : O(n)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> t(2, vector<int>(n+1));
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 || j == 0)
                    t[i%2][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    t[i%2][j] = 1 + t[(i+1)%2][j-1];
                else
                    t[i%2][j] = max(t[i%2][j-1], t[(i+1)%2][j]);
            }
        }
        
        return t[m%2][n];
    }
};


