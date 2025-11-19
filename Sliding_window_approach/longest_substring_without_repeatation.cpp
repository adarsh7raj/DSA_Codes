// brute force approach :
//TC :O(n^2)
//SC: O(1)

// optimal solution :

// Time Complexity: O(n)
// Space Complexity: O(min(m, n)) where m is the size of the character set
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
           int maxi=0;
           map<char,int>mp;
           
           int l=0;
           int r=0;
           while(r<s.size()){
         if(mp.count(s[r]) && mp[s[r]]>=l){
         
     l=mp[s[r]]+1;
           
         }
    int len=r-l+1;
     maxi=max(maxi,len);
     mp[s[r]]=r;
         r++;
           }
            return maxi;
        }
};