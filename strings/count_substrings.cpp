//TC: O(n) SC: O(1)

class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int n=s.size();
        int cnt_a=0;
        int cnt_b=0;
        int cnt_c=0;
        int left=0;
        int right=-1;
        int ans=0;
        while( right<n){
         
            if(cnt_a>=1 && cnt_b>=1 && cnt_c>=1){
                ans+=n-right;
                if(s[left]=='a'){
                    cnt_a--;
                }
                else if(s[left]=='b'){
                    cnt_b--;
                }
                else{
                    cnt_c--;
                }
                left++;
                
            }
            else{
                right++;
                   if(s[right]=='a'){
                cnt_a++;
            }
            else if(s[right]=='b'){
                cnt_b++;
            }
            else if(s[right]=='c'){
                cnt_c++;
            }
            }
        }
        return ans;
        
    }
};