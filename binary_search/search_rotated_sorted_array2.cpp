
// in this we have to search in rotated sorted array which may contain duplicates
// so the approach is similar to search in rotated sorted array without duplicates
// but while finding pivot we have to take care of duplicates
class Solution {
public:

int find_pivot(vector<int>& nums, int l, int r) {
        while(l < r) {
          
            while(l<r && nums[l]==nums[l+1]){ // to skip duplicates
                l++;
            }
            while(l<r && nums[r]==nums[r-1]){ // to skip duplicates
                r--;
            }

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
    
    int binary_search(vector<int>& nums, int l, int r, int target) {
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return -1;
    }
    bool search(vector<int>& nums, int target) {
      int n = nums.size();
        int pivot = find_pivot(nums, 0, n-1);
        cout<<pivot;
        if(nums[pivot] == target)
            return true;
        
        int idx = -1;
        idx = binary_search(nums, pivot+1, n-1, target);
        if(idx != -1){
            return true;
        }
        idx = binary_search(nums, 0, pivot-1, target);
        if(idx!=-1){
            return true;
        }
        return false ;
    
    }
};