
// User function Template for C++
// TC : O(n) where n is length of expression
// SC : O(n) for stack and output string
class Solution {
  public:
    string postToInfix(string s) {
        // Write your code here
        int i=0;
        int n=s.size();
        string ans;
        stack<string>st;
        while(i<n){
            char ch=s[i];
              if ((ch >= 'A' && ch <= 'Z') ||
                (ch >= 'a' && ch <= 'z') ||
                (ch >= '0' && ch <= '9')) {
                st.push(string(1,s[i]));
            }
            else{
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                string temp='('+s2+ s[i]+s1+')';
                st.push(temp);
            }
            i++;
        }
        return st.top();
    }
};