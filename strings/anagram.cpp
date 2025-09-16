//optimal approach : 
class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.size()!=t.size()){
                return false;
            }
            int count=0;
            unordered_map<char,int>m1;
            unordered_map<char,int>m2;
           for(int i=0;i<s.size();i++){
            m1[s[i]]++;
            m2[t[i]]++;
           } 
      for(auto it:m1){
        if(it.second==m2[it.first]){
            count++;
        }
        else{
            return false;
        }
      }
      if(count==m1.size()){
        return true;
      }
      else{
        return  false;
      }
        }
    };

    // another way to solve using single array:

    class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        int count[26] = {0}; // frequency array for a-z
        
        for(int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;  // increment count for s
            count[t[i] - 'a']--;  // decrement count for t
        }
        
        // check if all counts are zero
        for(int i = 0; i < 26; i++) {
            if(count[i] != 0) return false;
        }
        
        return true;
    }
};
