

//optimal solution using sliding window
// TC : O(2n) and SC: O(k)
class Solution {
public:
int subarray(vector<int>&nums ,int k){
     map<int,int>mp;
        int l=0;
        int r=0;
        int n=nums.size();
        int result=0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                    
                }
               
                l++;
            }
              
                result+=r-l+1; // we add all the subarrays ending at r with number of distinct elements <=k
            
            r++;
    }
    return result;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return subarray(nums,k)- subarray(nums,k-1);
}

};