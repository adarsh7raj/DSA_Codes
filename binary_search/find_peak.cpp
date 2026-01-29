
// not so good approach

//TC : O(logn)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        if(nums.size()==1){
            return 0;
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            if((mid==0 && nums[mid]>nums[mid+1]) || (mid==n-1 && nums[mid]>nums[mid-1])){
                return mid;

            }
           else if(mid>0 && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(mid>0 && nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                l=mid+1;
            }
            else if(mid>0 && nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1]){
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return -1;
    }
};

// more clean approach

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        if (n == 1) return 0;

        while (l < r) {
            int mid = l + (r - l) / 2;

            // peak
            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }
            // rising slope → right
            else if (mid < n - 1 && nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            }
            // falling slope or valley → left
            else if(mid>0 && nums[mid]<nums[mid-1]) {
                r = mid - 1;
            }
            else{
                r=mid-1;
            }
        }

        return l;
    }
};
