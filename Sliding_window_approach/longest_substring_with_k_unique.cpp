

// optimal solution using sliding window
// TC : O(2n) and SC: O(k)

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        map<char,int>mp;
        int l=0;
        int r=0;
        int n=s.size();
        int result=-1;
        while(r<n){
            mp[s[r]]++;
            while(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                    
                }
                l++;
            }
            if(mp.size()==k){
                result=max(result,r-l+1);
            }
            r++;
        }
        return result;
    }
};