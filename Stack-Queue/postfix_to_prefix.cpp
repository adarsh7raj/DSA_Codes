

// User function Template for C++
// TC : O(n) where n is length of expression
// SC : O(n) for stack and output string
class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
         
        int n=s.size();
         int i=0; 
      
        stack<string>st;
        while(i<n){
            char ch=s[i];
              if ((ch >= 'A' && ch <= 'Z') ||
                (ch >= 'a' && ch <= 'z') ||
                (ch >= '0' && ch <= '9')) {
                st.push(string(1,s[i]));
            }
            else{
                //we pop to previous elements and put them together
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                string temp=s[i]+s2+s1;
                st.push(temp);
            }
            i++;
        }
        return st.top();
    }
};