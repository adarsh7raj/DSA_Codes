

// User function Template for C++
// TC : O(n) where n is length of expression
// SC : O(n) for stack and output string
class Solution {
  public:
    string preToPost(string s) {
        
        int n=s.size();
         int i=n-1;
        string ans;
        stack<string>st;
        while(i>=0){
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
                string temp=s1+s2+s[i];
                st.push(temp);
            }
            i--;
        }
        return st.top();
    }
};