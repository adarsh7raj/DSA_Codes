
// TC: O(n) SC: O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
       stack<char>st;
       string ans="";
       int n=num.size();
       if(num.size()==k){
        return "0";
       }
       for(int i=0;i<n;i++){
          while(!st.empty() && st.top()>num[i] && k>0){
            st.pop();
            k--;
          }
          if(st.empty() && num[i]=='0'){
        
            continue;
          }
          st.push(num[i]);
       }    
        while(!st.empty()&& k>0){
            st.pop();
            k--;
        }  

        if(st.empty()){
            return "0";
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;   
    }
};