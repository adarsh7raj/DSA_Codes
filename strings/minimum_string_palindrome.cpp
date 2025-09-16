//Approach-1 (Recur + Memo - Using Straight Forward Pallindromic Property)
//T.C : O(n*n)
//S.C : O(n*n)

// here t[i][j] represents the minimum insertions needed to make the substring s[i..j] a palindrome from inddex i to j in string s
class Solution {
public:
    int t[501][501];
    int solve(int i, int j, string &s) {
 
        if(i >= j)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        if(s[i] == s[j])
            return t[i][j] = solve(i+1, j-1, s);
        
        return t[i][j] = 1 + min(solve(i, j-1, s), solve(i+1, j, s));
        
    }
    
    int minInsertions(string s) {
        int n = s.length();
        
        memset(t, -1, sizeof(t));
        
        return solve(0, n-1, s);
    }
};


//Approach-2 (Bottom Up - Using my favourite Palindrome Blue Print)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //State : dp[i][j] = min insertion to make s[i..j] a palindrome
        
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};

//Approach-3 (Using LCS)
//T.C : O(n*n)
//S.C : O(n*n)

//What t[m][n] means

//t[m][n] stores the length of the LCS between:

//The first m characters of s1 → s1[0..m-1]

// The first n characters of s2 → s2[0..n-1]
class Solution {
public:
    int t[501][501];
    
    int LCS(string& s1, string& s2, int m, int n) {
        if(m == 0 || n == 0)
            return t[m][n] = 0;
        
        if(t[m][n] != -1)
            return t[m][n];
        
        if(s1[m-1] == s2[n-1])
            return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        
        return t[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
    }
    
    int minInsertions(string s) {
        int m = s.length();
        
        memset(t, -1, sizeof(t));
        string temp = s;
        reverse(begin(temp), end(temp));
        
        int lcs_length = LCS(s, temp, m, m);
        
        return m - lcs_length;
    }
};


