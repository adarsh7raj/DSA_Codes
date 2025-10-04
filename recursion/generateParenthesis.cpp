// brute force approach :
// TC : O(2^(2n) * n) -> generating all combinations of length 2n and checking each for validity
// SC : O(n * 2^(2n)) for the ans storage + O(n) for recursion stack = O(n * 2^(2n))
// we can pass the str by reference this will make the SC to O(2n) only for the recurion stack
class Solution {
public:
    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') balance++;   // increment for '('
            else if (c == ')') balance--; // decrement for ')'

            // If at any point balance < 0, too many ')'
            if (balance < 0) return false;
        }

        // All '(' must be closed
        return balance == 0;
    }

    void solve(int n, vector<string> &ans, string str, int i) {
        if (i == 2 * n) {
            if (isValid(str)) {
                ans.push_back(str);
            }
            return;
        }

        // Choose '('
        solve(n, ans, str + "(", i + 1);

        // Choose ')'
        solve(n, ans, str + ")", i + 1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, ans, "", 0);
        return ans;
    }
};


// optimal solution:
// TC : O(2^n)
//SC:O(2n)
class Solution {
public:
    void solve(int n, vector<string> &ans, string str, int open, int close) {
        if (str.size() == 2 * n) {
            ans.push_back(str);
            return;
        }

        // Add '(' if we still have left
        if (open < n) {
            solve(n, ans, str + "(", open + 1, close);
        }

        // Add ')' if it won't break validity
        if (close < open) {
            solve(n, ans, str + ")", open, close + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, ans, "", 0, 0);
        return ans;
    }
};



