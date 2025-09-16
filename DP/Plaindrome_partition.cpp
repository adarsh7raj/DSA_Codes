
 // TC: Here, every start index (from 0..n-1) is computed once due to memoization.

// For each start, we try all possible end (up to n), and for each substring we check palindrome in O(n).

// So one call costs O(n^2), and we do it for n different starts.

//  Overall TC = O(n^3) (because n starts × n ends × n for palindrome check).
//  With palindrome precomputation (O(n^2) preprocessing), this can be reduced to O(n^2).

//  Space Complexity

// O(n^2) for storing results in memo.

// O(n^2) if we also precompute palindrome table.

// Recursion depth = O(n).
class Solution {
public:
    vector<vector<string>> result;
    unordered_map<int, vector<vector<string>>> memo;

    vector<vector<string>> partition(string s) {
        return dfs(s, 0);
    }

private:
    vector<vector<string>> dfs(string &s, int start) {
        if (start == s.length()) {
            return {{}};
        }

        if (memo.count(start)) return memo[start];

        vector<vector<string>> res;

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                string substr = s.substr(start, end - start + 1);
                auto partitions = dfs(s, end + 1);

                for (auto &p : partitions) {
                    vector<string> temp = {substr};
                    temp.insert(temp.end(), p.begin(), p.end());
                    res.push_back(temp);
                }
            }
        }

        return memo[start] = res;
    }

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};
