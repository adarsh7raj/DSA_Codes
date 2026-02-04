
//TC: O(log n) , SC: O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
      string s="";
      string g="";
      while(start>=1){
        if(start%2==0){
            s+='0';
        }
        else{
       s+='1';
        }
       
        start=start/2;
      }  
      reverse(s.begin(),s.end());
          while(goal>=1){
        if(goal%2==0){
            g+='0';
        }
        else{
 g+='1';
        }
       
        goal=goal/2;
      }
      if (s.empty()) s = "0";
        if (g.empty()) g = "0";
      reverse(g.begin(),g.end());
      int count=0;
      if(s.size()>g.size()){
        while(s.size()-g.size()>0){
            g='0'+g;
        }
      }
      else{
        while(g.size()-s.size()>0){
            s='0'+s;
        }
      }
      for(int i=g.size()-1;i>=0;i--){
    if(g[i]!=s[i]){
        count++;
    }
      }
      return count;  
    }
};


