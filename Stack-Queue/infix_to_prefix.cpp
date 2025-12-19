
//TC : O(n) where n is length of expression
//SC : O(n) for stack and output string

class Solution {
public:
    int priority(char ch) {
        if (ch == '^') return 3;
        if (ch == '*' || ch == '/') return 2;
        if (ch == '+' || ch == '-') return 1;
        return -1;
    }

    string infixToPrefix(string &s) {
        stack<char> st;
        string ans = "";

        // Step 1: Reverse
        reverse(s.begin(), s.end());

        // Step 2: Swap brackets
        for (char &ch : s) {
            if (ch == '(') ch = ')';
            else if (ch == ')') ch = '(';
        }

        // Step 3: Process
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
                if (!st.empty()) st.pop();
            }

            // Operator
            else {
                while (!st.empty() && st.top() != '(' &&
                      (priority(ch) < priority(st.top()) ||
                      (priority(ch) == priority(st.top()) && ch == '^'))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        // Step 4: Pop remaining
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Step 5: Reverse result
        reverse(ans.begin(), ans.end());

        return ans;
    }
};



