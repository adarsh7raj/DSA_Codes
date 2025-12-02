// brute force approach : 

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int result=0;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp=temp+s[j];
                if(temp.contains("a") && temp.contains("b") && temp.contains("c")){
                    result++;

                }
            }
        } 
        return result;
    }
};

// optimal solution using sliding window
// TC : O(2n) and SC: O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int result=0;
        int l=0;
        int r=0;
        map<char,int>mp;
        
        while(r<n){
       mp[s[r]]++;
       while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
        result+=n-r;  // if abc is valid then abca is also valid and abcab is also valid and so on.
        mp[s[l]]--;
        l++;
       }
        r++;
        } 
        return result;
    }
};