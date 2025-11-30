// brute force approach : 
// TC: O(n*d) and SC: O(n) where d is the number of unique elements at a time.

class Solution {
public:
int maxFreq(unordered_map<int,int>&mp){
    int maxi=0;
    for(auto it:mp){
        if(it.second>maxi){
            maxi=it.second;
        }
       
    }
     return maxi;
}
    int characterReplacement(string s, int k) {
        int l=0;
        int n=s.size();
        int r=0;
        int maxi=0;
        unordered_map<int,int>mp;
        int max_freq=0
        while(r<n){
            mp[s[r]]++;
            int max_freq=maxFreq(mp);
            cout<<max_freq;
            int len=r-l+1;
            if(len-max_freq>k){
                mp[s[l]]--;
                l++;
            }
            else{
                maxi=max(maxi,len);
            }
            r++;
        }
      return maxi;
    }
};




//optimal solution using sliding window
// TC : O(n) and SC:O(n)
class Solution {
public:

    int characterReplacement(string s, int k) {
        int l=0;
        int n=s.size();
        int r=0;
        int maxi=0;
        vector<int>freq(26,0);
        int max_freq=0;
        while(r<n){
            freq[s[r]-'A']++;
            max_freq=max(max_freq,freq[s[r]-'A']);
           
            cout<<max_freq;
            int len=r-l+1;
            if(len-max_freq>k){
                freq[s[l]-'A']--;
                l++;
            }
            else{
                maxi=max(maxi,len);
            }
            r++;
        }
      return maxi;
    }
};