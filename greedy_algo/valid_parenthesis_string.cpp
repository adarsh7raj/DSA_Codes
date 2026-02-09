

// brute force approach this will give TLE
//TC: O(3^n) because for every '*' we have 3 choices
class Solution {
public:
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

bool solve(vector<string>&ans,string & s,string temp,int i){
   if(i==s.size()){
      if(isValid(temp)){
        return true;
   }
      return false;
   }

 if(s[i]=='*'){
return solve(ans,s,temp+'(',i+1)||solve(ans,s,temp+')',i+1)||solve(ans,s,temp,i+1);
   }
   else{
     return solve(ans,s,temp+s[i],i+1);
   }
   return false;
}
    bool checkValidString(string s) {
     string temp="";
     vector<string>ans;
       return  solve(ans,s,temp,0);
       
    }
};


//dp approach

// t[idx][open] stores whether it is possible to make a valid parentheses string from index idx to
//  the end of the string, given that there are currently open unmatched '('.
class Solution {
public:
    
    int t[101][101];
    bool solve(int idx, int open, string& s, int n) {
        if(idx == n) {
            return open == 0;
        }
        
        if(t[idx][open] != -1) {
            return t[idx][open] == 1 ? true : false;
        }
        
        bool isValid = false;
        
        if(s[idx] == '*') {
            if(open > 0)
                isValid |= solve(idx+1, open-1, s, n); //Treating * as )
            
            isValid |= solve(idx+1, open+1, s, n); //Treating * as (
            
            isValid |= solve(idx+1, open, s, n);   //Treating * as ''
        } else if(s[idx] == '(') {
            isValid |= solve(idx+1, open+1, s, n);
        } else if(open > 0) {
            isValid |= solve(idx+1, open-1, s, n);
        }
        
        return t[idx][open] = isValid;
    }
    
    bool checkValidString(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        return solve(0, 0, s, n);
        
    }
};


// bottom up approach

//Approach-2 (Using Bottom Up)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public: 
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> t(n + 1, vector<bool>(n + 1, false));
        //State Definition :
        //t[i][j] = if the string from index i to n-1 is valid or not having j open brackets
        t[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int open = 0; open <= n; open++) {
                bool isValid = false;

                if (s[i] == '*') {
                    isValid |= t[i + 1][open + 1]; //Treating * as ( --> solve(i+1, open+1)
                    if (open > 0) {
                        isValid |= t[i + 1][open - 1]; //Treating * as ) --> solve(i+1, open-1)
                    }
                    isValid |= t[i + 1][open]; //Treating * as empty --> solve(i+1, open)
                } else {
                    if (s[i] == '(') {
                        isValid |= t[i + 1][open + 1]; //solve(i+1, open+1)
                    } else if (open > 0) {
                        isValid |= t[i + 1][open - 1]; //solve(i+1, open=-1)
                    }
                }
                t[i][open] = isValid;
            }
        }

        return t[0][0];
    }
};

//Approach-3 (Using two Stacks) - No DP required
//T.C : O(n)
//S.C : O(n)
class Solution {
public: 
    bool checkValidString(string s) {
        stack<int> openSt;
        stack<int> asterisksSt;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                openSt.push(i);
            } else if (ch == '*') {
                asterisksSt.push(i);
            } else {
                if (!openSt.empty()) {
                    openSt.pop();
                } else if (!asterisksSt.empty()) {
                    asterisksSt.pop();
                } else {
                    return false;
                }
            }
        }

        //This post processing will be required for cases like - "*(())(*"
        while (!openSt.empty() && !asterisksSt.empty()) {
            if (openSt.top() > asterisksSt.top()) {
                return false;
            }
            openSt.pop();
            asterisksSt.pop();
        }

        return openSt.empty();
    }
};


// optimal solution

//TC : O(n) SC : O(1)

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // '*'
            
                low--;      // treat as ')'
                high++;     // treat as '('
            }

            if (high < 0) return false;
            if (low < 0) low = 0;
        }

        return low == 0;
    }
};
