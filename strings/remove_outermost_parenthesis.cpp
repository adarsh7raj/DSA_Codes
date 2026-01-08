

// using stack:
//TC: O(n) SC: O(n)
class Solution {
public:

    string removeOuterParentheses(string s) {
       
        string ans="";
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(!st.empty()){
                    ans+=s[i];
                }
                st.push(s[i]);
            }
            else{
                st.pop();
                if(!st.empty()){
                    ans+=s[i];
                }
            }
        }
    
        
        return ans;
    }
};


// without using stack:
//TC: O(n) SC: O(1)

class Solution {
public:

    string removeOuterParentheses(string s) {
       
        string ans="";
        int depth=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
               if(depth>0){
                ans+=s[i];
               }
               depth++;
              
            }
            else{
        
          depth--;
              if(depth>0){
                ans+=s[i];
              }
            }
        }
    
        
        return ans;
    }
};