// TC : O(n) where n is length of expression
// SC : O(n) for stack and output string
class Solution {
public:
    int priority(char ch) {
        if (ch == '^') return 3;
        if (ch == '*' || ch == '/') return 2;
        if (ch == '+' || ch == '-') return 1;
        return -1;
    }

    string infixToPostfix(string& s) {
        stack<char> st;
        string ans = "";

        for (char ch : s) {

            // Operand
            if ((ch >= 'A' && ch <= 'Z') ||
                (ch >= 'a' && ch <= 'z') ||
                (ch >= '0' && ch <= '9')) {
                ans += ch;
            }

            // '('
            else if (ch == '(') {
                st.push(ch);
            }

            // ')'
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // remove '('
            }

            // Operator
            else {
                while (!st.empty() && st.top() != '(' &&
                      (priority(ch) < priority(st.top()) ||
                      (priority(ch) == priority(st.top()) && ch != '^'))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
