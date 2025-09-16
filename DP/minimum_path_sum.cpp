
// LeetCode 931 - Minimum Falling Path Sum
// C++ solution using Dynamic Programming   

//Approach-1 (Recur + Memoization) : O(m*n) (New test Case has been added, this will give TLE in last Test Case) (49 / 50 testcases passed)
//T.C : O(m*n)
//S.C : O(101) ~ O(1) (Excluding stack recursion space)
class Solution {
public:
    int MFS(vector<vector<int>>& A, int row, int col, vector<vector<int>>& t) {
        if(row == A.size()-1)
            return A[row][col];
        if(t[row][col] != -1)
            return t[row][col];
        
        int minSum = INT_MAX;
        
        for(int shift = -1; shift<=1; shift++) {
            if(col + shift >=0 && col+shift < A[row].size()) {
                minSum = min(minSum, A[row][col] + MFS(A, row+1, col+shift, t));
            }
        }
        
        return t[row][col] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(); //row
        int n = m; //column
        vector<vector<int>> t(101, vector<int>(101));
        for(int i = 0; i<101; i++) {
            for(int j = 0; j<101; j++) {
                t[i][j] = -1;
            }
        }
        int result = INT_MAX;
        for(int col = 0; col<n; col++) {
            result = min(result, MFS(A, 0, col, t));
        }
        return result;
    }
};
//Approach-2 (Bottom-Up DP) : O(m*n) (This will pass all test cases)
//T.C : O(m*n)
//S.C : O(m*n) (DP table)



class Solution {
public:
    int MFS(vector<vector<int>>& A) {
        int m = A.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // Base case
        for (int col = 0; col < m; col++) {
            dp[0][col] = A[0][col];
        }

        // Fill DP table
        for (int row = 1; row < m; row++) {
            for (int col = 0; col < m; col++) {
                int up       = dp[row-1][col];
                int up_left  = (col > 0) ? dp[row-1][col-1] : INT_MAX / 2;
                int up_right = (col < m-1) ? dp[row-1][col+1] : INT_MAX / 2;

                dp[row][col] = A[row][col] + min({up, up_left, up_right});
            }
        }

        // Answer is min in the last row
        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }

    int minFallingPathSum(vector<vector<int>>& A) { 
        return MFS(A);
    }
};




//Approach-3 (Bottom Up Space Optimized)
//T.C : O(m*n)
//S.C :  O(m*n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> prev(n);
        for(int col = 0; col<n; col++)
            prev[col] = A[0][col];
        
        for(int row = 1; row<n; row++) {
            vector<int> curr(n);
            for(int col = 0; col<n; col++) {
                curr[col] = A[row][col] + min({prev[max(0, col-1)],  prev[col],  prev[min(n-1, col+1)]});
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
