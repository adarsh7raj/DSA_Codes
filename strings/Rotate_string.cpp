//TC: O(n^2) SC: O(1)

class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            if(s==goal){
                return true;
            }
            s.push_back(s[0]);
            s.erase(0,1);
            cout<<s;
        }
 return false;
    }
   
};

//optimal approach
//TC: O(n) SC: O(n)
class Solution {
public:
    bool rotateString(string s, string goal) {
       if(s.size()!=goal.size()){
        return false;
       }

       if((s+s).find(goal) != string::npos){
        return true;
       }
 return false;
    }
   
};