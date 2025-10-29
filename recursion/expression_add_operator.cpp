

// brute force appraoch : 
// in this code we are not using for loop instead of that to habdle cases like digit="123"
 //we are merging the digits like 12+3 by a separate recursive call
 // this will  not work as we are  not handling the cases where number starts with 0 like 105
 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    string num;
    int target;

    void solve(int index, string expr, long value, long prev) {
        // Base case: if we've used all digits
        if (index == num.size()) {
            if (value == target) ans.push_back(expr);
            return;
        }

        // Take current digit
        int digit = num[index] - '0';

        // Join with previous number (no operator) we not using for loop to create different sizes of numbers
        if (expr.back() != '+' && expr.back() != '-' && expr.back() != '*')
            solve(index + 1, expr + num[index], value * 10 + digit, prev * 10 + digit);

        // Add '+'
        solve(index + 1, expr + "+" + num[index], value + digit, digit);

        // Add '-'
        solve(index + 1, expr + "-" + num[index], value - digit, -digit);

        // Add '*'
        solve(index + 1, expr + "*" + num[index],
              value - prev + prev * digit, prev * digit);
    }

    vector<string> addOperators(string n, int t) {
        num = n;
        target = t;
        if (num.empty()) return ans;
        int first = num[0] - '0';
        solve(1, string(1, num[0]), first, first);
        return ans;
    }
};

int main() {
    Solution s;
    string num = "123";
    int target = 6;
    vector<string> result = s.addOperators(num, target);
    for (auto &expr : result)
        cout << expr << endl;
    return 0;
}


// correct way to solve the question : 
// without using the for loop:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(string &num, int target, int index, string expr, long long value, long long last, vector<string> &ans) {
        // Base case: all digits used
        if (index == num.size()) {
            if (value == target)
                ans.push_back(expr);
            return;
        }

        int digit = num[index] - '0';

        // -------------------------------------
        // 1️⃣ Join with previous number (no operator)
        // -------------------------------------
        // Only allowed if the previous number didn’t start with '0'
        int lastOp = expr.find_last_of("+-*");
        int lastNumStart = (lastOp == string::npos) ? 0 : lastOp + 1;
        if (!(expr[lastNumStart] == '0' && lastNumStart == expr.size() - 1)) {
            dfs(num, target, index + 1,
                expr + num[index],
                value * 10 + digit, last * 10 + digit, ans);
        }

        // -------------------------------------
        // 2️⃣ Add '+'
        // -------------------------------------
        dfs(num, target, index + 1,
            expr + "+" + num[index],
            value + digit, digit, ans);

        // -------------------------------------
        // 3️⃣ Add '-'
        // -------------------------------------
        dfs(num, target, index + 1,
            expr + "-" + num[index],
            value - digit, -digit, ans);

        // -------------------------------------
        // 4️⃣ Add '*'
        // -------------------------------------
        dfs(num, target, index + 1,
            expr + "*" + num[index],
            value - last + last * digit, last * digit, ans);
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty()) return ans;

        long long first = num[0] - '0';
        dfs(num, target, 1, string(1, num[0]), first, first, ans);
        return ans;
    }
};

// 


// by using the for loop  

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Function to evaluate the expression
    void dfs(string& num, int target, int start, long long current_value, long long last_operand, string expression, vector<string>& result) {
        // Base case: If we've reached the end of the string
        if (start == num.size()) {
            // If the expression evaluates to the target, add it to result
            if (current_value == target)  
                result.push_back(expression);
            return;
        }
        
        // Loop through all substrings starting from 'start' index
        for (int i = start; i < num.size(); i++) {
            // Skip leading zeros in numbers
            if (i > start && num[start] == '0') return;
            // Get the current number
            string current_num = num.substr(start, i - start + 1); 
            long long current_num_val = stoll(current_num);
            
            // If we are at the first number, just start the expression
            if (start == 0) {
                dfs(num, target, i + 1, current_num_val, current_num_val, current_num, result);
            } else {
                // Add the current number with '+'
                dfs(num, target, i + 1, current_value + current_num_val, current_num_val, expression + "+" + current_num, result);
                
                // Add the current number with '-'
                dfs(num, target, i + 1, current_value - current_num_val, -current_num_val, expression + "-" + current_num, result);
                
                // Add the current number with '*'
                dfs(num, target, i + 1, current_value - last_operand + last_operand * current_num_val, last_operand * current_num_val, expression + "*" + current_num, result);
            }
        }
    }
    // To store the valid expressions
    vector<string> addOperators(string num, int target) {
        vector<string> result;  
        // Start DFS with empty expression
        dfs(num, target, 0, 0, 0, "", result);  
        return result;
    }
};

int main() {
    string num = "123";  
    int target = 6;      
    Solution sol;        
    
    // Get all valid expressions
    vector<string> result = sol.addOperators(num, target);
    
    // Print the results
    for (const string& expr : result) {
        cout << expr << " "; 
    }
    return 0;
}