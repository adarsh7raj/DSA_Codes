class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;
        int sign = 1;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 4. Handle overflow BEFORE it happens
            //actually the condition is :  result * 10 + digit <= INT_MAX
            // we do not have to check that result >INT_MAX beacuse it is already smaller than INT_MAX
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};


// another approach

class Solution {
public:
    int myAtoi(string s) {
    int i = 0, n = s.size();
    
    // Step 1: skip leading spaces
    while (i < n && s[i] == ' ') i++;

    // Step 2: check sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') sign = -1;
        i++;
    }

    // Step 3: read digits and build number
    long long num = 0; // use long long to detect overflow
    while (i < n && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');

        // Step 4: handle overflow
        if (num * sign > INT_MAX) return INT_MAX;
        if (num * sign < INT_MIN) return INT_MIN;

        i++;
    }

    return (int)(num * sign);
}
};


// recursive approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(string &s, int i, long long num, int sign) {
        // Base case: end of string OR non-digit character
        if (i >= s.size() || !isdigit(s[i])) {
            return (int)(num * sign);
        }

        // Build number
        num = num * 10 + (s[i] - '0');

        // Overflow check
        if (num * sign > INT_MAX) return INT_MAX;
        if (num * sign < INT_MIN) return INT_MIN;

        // Recursive call for next character
        return helper(s, i + 1, num, sign);
    }

    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Start recursive digit parsing
        return helper(s, i, 0, sign);
    }
};

int main() {
    Solution sol;
    cout << sol.myAtoi("42") << endl;              // 42
    cout << sol.myAtoi("   -42") << endl;          // -42
    cout << sol.myAtoi("4193 with words") << endl; // 4193
    cout << sol.myAtoi("words 987") << endl;       // 0
    cout << sol.myAtoi("-91283472332") << endl;    // INT_MIN
    cout << sol.myAtoi("91283472332") << endl;     // INT_MAX
}
