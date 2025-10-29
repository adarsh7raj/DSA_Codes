// Time Complexity

// Your recursion generates all binary strings of length n.

// At each index i, you branch into two recursive calls ('0' and '1').

// Depth of recursion = n.

// Total number of leaves in recursion tree = 2^n.

// So number of recursive calls = O(2^n).

// ⚠️ But notice → at each leaf node, you do ans.push_back(str).

// Copying a string of length n into ans costs O(n).

// And there are 2^n such strings.

// 👉 So the true TC is:

//O(2^n*n)
// 🔹 Space Complexity

// Recursion stack:

// Max depth = n.

// Each frame keeps local variables and copies of str (but str is passed by value, which means each call creates a copy of the string!).

// So recursion overhead = O(n^2) worst case (because copying string of size n at each level).

// ⚡ If you pass string& str instead, recursion stack would be only O(n).

// Result storage (ans):

// You store 2^n strings, each of length n.

// Space = O(n \cdot 2^n).

// 👉 So the total SC is dominated by result storage:

//O(n * 2^n)



class Solution {
  public:
  void solve(int n,vector<string>&ans,string str,int i){
     if(i==n){
         ans.push_back(str);
         return;
     }
     str+='0';
     solve(n,ans,str,i+1);
     str.pop_back();
     str+='1';
     solve(n,ans,str,i+1);
  }
    vector<string> binstr(int n) {
        // code here
        vector<string>ans;
        solve(n,ans,"",0);
        return ans;
    }
}
// slightly optimized approach  this 
// TC : O(2^n * n)
// SC : O(n * 2^n) for the ans storage + O(n) for recursion stack = O(n * 2^n)
class Solution {
public:
    void solve(int n, vector<string> &ans, string &str, int i) {
        if (i == n) {
            ans.push_back(str);
            return;
        }
        // Choose '0'
        str.push_back('0');
        solve(n, ans, str, i + 1);
        str.pop_back(); // backtrack

        // Choose '1'
        str.push_back('1');
        solve(n, ans, str, i + 1);
        str.pop_back(); // backtrack
    }

    vector<string> binstr(int n) {
        vector<string> ans;
        string str;
        str.reserve(n); // reserve space to avoid reallocations
        solve(n, ans, str, 0);
        return ans;
    }
};
