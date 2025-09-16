// brute force approach : TC: O(nlogn) SC: O(1) we use binary search to find if the element is present or not
// brute force approach : TC : if we use linear search O(n^2) SC: O(1)



//better approach : 
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            int n=nums.size();
            vector<int> ans;
            sort(nums.begin(),nums.end());
            int count=0;
            int result;
            int last_smaller=INT_MIN;
            int longest=1;
            if(n==0){
                return 0;
            }
            for(int i=0;i<n;i++){
            if(nums[i]-1==last_smaller){
                
                count++;
                last_smaller=nums[i];
            }
            else if(nums[i]!=last_smaller){
               
                last_smaller=nums[i];
                count=1;
            }
               longest=max(longest,count);
            }
            
            return longest;
        }
    };

    //optimal solution:  TC : O(2n)  SC: O(n)
    class Solution {
        public:
            int longestConsecutive(vector<int>& nums) {
                int n=nums.size();
                int longest=1;
                unordered_set<int>st;
                if(n==0){
                    return 0;
                }
                for(int i=0;i<n;i++){
                 st.insert(nums[i]);
                }
                for(auto it:st){ 
                    if(!(st.count(it-1))){  // it can be starting point of sequence
                        int count=1;
                        int x=it;
                        while(st.count(x+1)){
                            count++;
                            x++;
                        }
                        longest=max(longest,count);
                    }
                }
                return longest;
            };
        };