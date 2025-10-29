

// // So why do we pass j = 0 there?

// Because once we’ve picked one letter from the current digit (say 'a' from "abc"),
// we need to move to the next digit (i + 1) — and start its letter choices from the first letter (index 0) again.

// We’re done with the current digit’s letter choice, so for the next digit,
// j should restart from 0.

// If we didn’t reset j = 0, the next recursive call would incorrectly continue from the middle of the next digit’s 
// letters — which makes no logical sense, since each new digit starts fresh with its own letters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int j, string &digits, vector<string> &mapping, string temp, vector<string> &result) {
        // base case: if we have formed a string of length == digits length
        if (i == digits.size()) {
            result.push_back(temp);
            return;
        }

        string letters = mapping[digits[i] - '0'];
        if (j >= letters.size()) return;

        // pick current letter
        temp.push_back(letters[j]);
        solve(i + 1, 0, digits, mapping, temp, result);
        temp.pop_back();

        // not pick current letter → move to next letter option
        solve(i, j + 1, digits, mapping, temp, result);
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping(10, "");
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        vector<string> result;
        string temp = "";
        solve(0, 0, digits, mapping, temp, result);
        return result;
    }
};

// better approach : 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, string &digits, vector<string> &mapping, string temp, vector<string> &result) {
        // base case: if we have formed a string of length == digits length
        if (i == digits.size()) {
            result.push_back(temp);
            return;
        }

        // pick current letter
        string letters = mapping[digits[i] - '0'];
        for(auto ch:letters){
        temp.push_back(ch);
        solve(i + 1, digits, mapping, temp, result);
        temp.pop_back();
        }
        
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping(10, "");
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        vector<string> result;
        string temp = "";
        solve(0, digits, mapping, temp, result);
        return result;
    }
};