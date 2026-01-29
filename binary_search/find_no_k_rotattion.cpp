
// similar to find pivot element in rotated sorted array
// TC: O(log N)
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        int l=0;
        int r=nums.size()-1;
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] > nums[r]) {
                l = mid+1;
            } 
            else {
                r = mid;
            }
        }
        return r;
    }
};
