// optimal solution : O(n*m):
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int n=strs.size();
            bool istrue=true;
            string ans="";
            for(int i=0;i<strs[0].size();i++){
                  
                for(int j=1;j<n;j++){
             
                if(strs[j-1][i]!=strs[j][i]){
                    istrue=false;
                    break;
                }
              
                }
                if(istrue){
           ans=ans+strs[0][i];
                }
                if(!istrue){
                    break;
                }
                
            }
            return ans;
    
        }
    };

    // can be done as also : 
    class Solution {
        public:
            string longestCommonPrefix(vector<string>& strs) {
                int n=strs.size();
                
                string ans="";
                for(int i=0;i<strs[0].size();i++){
                      
                    for(int j=1;j<n;j++){
                 
                    if(strs[j-1][i]!=strs[j][i]){
                      
              return ans;
                    }
                  
                    }
                 
               ans=ans+strs[0][i];
                
                    
                }
                return ans;
        
            }
        };