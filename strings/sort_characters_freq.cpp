//TC: O(N) SC: O(N)

class Solution {
public:
    string frequencySort(string s) {
      unordered_map<char,int>mp;
      string ans="";
      for(auto ch: s){
        mp[ch]++;
      }
      priority_queue<pair<int,char>>pq;
      for(auto it:mp){
        pq.push({it.second,it.first});
      }

      while(!pq.empty()){
        int len=pq.top().first;
        while(len>0){
            ans+=pq.top().second;
            len--;
        }
        pq.pop();
      }
        return ans;
    }
};