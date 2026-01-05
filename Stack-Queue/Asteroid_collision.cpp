

// TC : O(n) SC: O(n)  this is also optimal but code is not standard , without using stack: mn
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      vector<int>ans;
      int n=asteroids.size();
    

         for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                ans.push_back(asteroids[i]);
            }
            else{
                int last_top;
                while(ans.size()!=0 && abs(asteroids[i])>ans.back()){
                    if(ans.back()<0){
                        ans.push_back(asteroids[i]);
                        break;
                    }
                    last_top=ans.back();
                    ans.pop_back();
                }
                if( ans.size()!=0 && ans.back()==abs(asteroids[i])){
                    ans.pop_back();
                }
                else if(ans.size()==0){
                    ans.push_back(asteroids[i]);
                }
            }
         }
    return ans;

        }  
};
// optimized TC : O(n) SC: O(n) without using stack:






