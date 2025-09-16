// brute force O(n):
//we can use xor method or we iterate using single for loop.


//optimal solution: O(logn):
// intituation is we have to find which side is having odd number of elements (left or right) we move towards that side.
class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int left = 0;
            int right = nums.size() - 1;
            int n = nums.size();
            int mid=0;
            while (left <= right) {
                 mid = (left + right) / 2;
                
                if ((mid > 0 && (nums[mid] != nums[mid - 1])) &&( mid < n - 1 && (nums[mid] != nums[mid + 1]))) {
                  
                    return nums[mid];
                } else {
                    if (mid>0&&nums[mid] == nums[mid - 1]) {
                        int leftSize = mid - left - 1;
                        if (leftSize % 2) {
                            right = mid - 2;
                        } else {
                            left = mid + 1;
                        }
                    } else {
                        int leftSize = mid - left;
                        if (leftSize % 2 ) {
                            right = mid - 1;
                        } else {
                        
                                left = mid + 2;
                            
                
                        }
                    }
                }
            }
    
            return nums[mid]; // or return -1 if the element must exist
        }
    };
    