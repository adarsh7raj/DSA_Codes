// optimal approach : O(n):
class Solution {
    public:
        int romanToInt(string s) {
            int n=s.size();
            map<char,int>m;
            
            int res=0;
            m['I']=1;
            m['V']=5;
            m['X']=10;
            m['L']=50;
            m['C']=100;
            m['D']=500;
            m['M']=1000;
      int right=1;
      int left=0;
    
      while(left<n){
      if(m[s[left]]>=m[s[right]]){
        res=res+m[s[left]];
        left++;
        right++;
    
      }
      else if(m[s[left]]<m[s[right]]){
        int sub=m[s[right]]-m[s[left]];
        res=res+sub;
        left+=2;
        right+=2;
      }
      else{
        res=res+m[s[left]];
        left++;
    
      }
      }
      return res;
        }
    };