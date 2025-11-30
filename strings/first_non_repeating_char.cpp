// TC : O(2n):
// SC : O(n):

class Solution {
public:
    int firstUniqChar(string s) {
    int n=s.size();
    map<char,int>mp;
     for(char c:s){
        mp[c]++;
     }
     for(int i=0;i<s.size();i++){
      if(mp[s[i]]==1){
        return i;
      }
     }
     return -1;
    }
};