// TC: O(log N)
// SC: O(1) 

class Solution {
public:
    int find_pivot(vector<int>& nums, int l, int r) {
        
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return nums[r];
    }