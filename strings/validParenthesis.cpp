// Most important are two condition to check for valid parenthesis
// 1. At any point in the string, number of closing parenthesis should not be more than opening parenthesis
// 2. At the end of the string, number of opening and closing parenthesis should be equal
// 3.Number of opening parenthesis can be greater than closing parenthesis at any point in the string
// because we can always add closing parenthesis later to make it valid,but as soon as closing 
// parenthesis are more than opening parenthesis at any point in the string, it can never be valid parenthesis

// optimal solution
// TC : O(n)
// SC : O(1)
#include <iostream>
#include <string>
using namespace std;

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

int main() {
    string str = "(()())";
    if (isValid(str)) cout << "Valid\n";
    else cout << "Invalid\n";
}

//stack based approach

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty()) return false; // No matching '('
            st.pop();
        }
    }

    return st.empty(); // True if all '(' are matched
}