
// TC :O(n^2)

class Solution {
public:
    bool isValid(const string& s, const unordered_set<string>& wordSet, int start, int end) {
        return wordSet.count(s.substr(start, end - start + 1));
    }

    bool isPossible(const string& s, const unordered_set<string>& wordSet, int start, vector<int>& dp) {
        if (start == s.size()) return true;
        if (dp[start] != -1) return dp[start];

        for (int end = start; end < s.size(); end++) {
            if (isValid(s, wordSet, start, end)) {
                if (isPossible(s, wordSet, end + 1, dp)) {
                    return dp[start] = true;
                } 
                //We can not use else statement here because we need to check all possible end indices and branchs think it for example 
                //like s = "aaaaaaa"     wordDict = ["aaaa", "aaa"] 
                // else{
                //     return false;
                // }
            }
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);  // -1: unvisited, 1: true, 0: false
        return isPossible(s, wordSet, 0, dp);
    }
};
