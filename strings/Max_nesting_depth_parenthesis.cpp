// TC: O(n) SC: O(n)

class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int maxi=INT_MIN;
        for(auto ch: s){

            if(ch=='('){
                st.push(ch);
                int len=st.size();
                maxi=max(len,maxi);
            }
            else if(ch==')'){
                st.pop();
            }
        }
        if(maxi==INT_MIN){
            return 0;
        }
        return maxi;
    }
};

// we can also do this without using stack
// TC: O(n) SC: O(1)
class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int maxi=INT_MIN;
        for(auto ch: s){

            if(ch=='('){
                depth++;
                maxi=max(depth,maxi);
            }
            else if(ch==')'){
                depth--;
            }
        }
        if(maxi==INT_MIN){
            return 0;
        }
        return maxi;
    }
};