// TC : O(n):

class Solution {
public:
    bool isValid(string s) {
        int i=0;
      
        stack<char>st;
        if(s.size()==1 || s.size()==0){
        return false;
        }
        while(i<s.size()){
        
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
             
     st.push(s[i]);
            }
        else{
           
            if(st.size()==0){
                return false;
            }
            char x=st.top();
            if(x=='(' && s[i]==')'){
                st.pop();
            }
            else if(x=='{' && s[i]=='}'){
                st.pop();
            }
            else if(x=='[' && s[i]==']'){
                st.pop();
            }
            else{
                return false;
            }
        }
        i++;

    }
    if(!st.empty()){
        return false;
    }
 
    else{
        return true;
    }
   
    }
};