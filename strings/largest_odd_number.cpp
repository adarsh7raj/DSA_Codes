//TC: O(n) SC: O(1)
class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
     for(int i=num.size()-1;i>=0;i--){
      int digit=num[i]-'0';
      if(digit%2==1){
        ans=num.substr(0,i+1);
        return ans;
      }
     }   
     return ans;
    }
};