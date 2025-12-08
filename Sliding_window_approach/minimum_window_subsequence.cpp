// brute force approach : 
// TC : O(n^3) and SC: O(1)
class Solution {
  public:
  bool  is_contains(string temp,string s2){
      if(temp.size()<s2.size()){
          return false;
      }
      int j=0;
      for(int i=0;i<temp.size();i++){
          if(temp[i]==s2[j]){
              j++;
          }
          
      }
      if(j!=s2.size()){
          return false;
      }
      return true;
      
  }
    string minWindow(string& s1, string& s2) {
        // Code here
        int n=s1.size();
        int mini=INT_MAX;
        string result="";
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
              temp.push_back(s1[j]);
              if(is_contains(temp,s2)){
                  if(mini>temp.size()){
                      result=temp;
                      mini=temp.size();
                  }
                  break;
              }
            }
        }
        return result;
    }
};



// optimal solution using sliding window    

// TC : O(2n) and SC: O(1)