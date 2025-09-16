//brute force approach
int n=nums.size();
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(nums[i]+nums[j]==target){
            return {i,j};
        }
    }
}


//better  approach : TC :O(nlogn)
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n=nums.size();
            vector<int> ans;
            map<int,int>m;
            for(int i=0;i<n;i++){
               if(m.count((target-nums[i]))){
                ans.push_back((m[(target-nums[i])]));
                   ans.push_back(i);
                   return ans;
               }
               else{
                m[nums[i]]=i;
               }
            }
           
            return ans;
        }
    };


    // optimal solution : O(nlogn);
    class Solution {
        public :
        vector<int> twoSum(vector<int>&nums,int target){
            int left=0;
            int right=nums.size()-1;
            sort(nums.begin(),nums.end());
            while(left<=right){
           if(nums[left]+nums[right]==target){
            vector<int>ans;
            ans.push_back(nums[left]);
            ans.push_back(nums[right]);
            return ans;
           }
           else if(nums[left]+nums[right]>target){
            right--;
           }
           else{
            left++;
           }
            }
            return ans;
        }
    }