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
    




    

//Approach : 2 (Using Binary Search) : O(log(n))
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int mid;
        
        while(l < r) {
            mid = l + (r-l)/2;
            bool isEven = (r-mid)%2==0;
            
            if(nums[mid] == nums[mid+1]) {
                if(isEven) {
                    l = mid+2;
                } else {
                    r = mid-1;
                }
            } else if(nums[mid] == nums[mid-1]) {
                if(isEven) {
                    r = mid-2;
                } else {
                    l = mid+1;
                }
            } else {
                return nums[mid];
            }
        }
        
        return nums[l]; //or, nums[r]
    }
};


//Approach : 3 (Another similar to Approach-2)
/*
    Some example to do a dry run to understand better:
    {1, 1, 2, 2, 3, 4, 4}
    {1, 1, 2, 3, 3}
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0;
        int h = n-1;
        
        while(l < h) {
            int mid = l + (h-l)/2;
            
            bool isEven = (h-mid)%2 == 0;
            
            if(nums[mid] == nums[mid+1]) {
                if(isEven) {
                    l = mid+2;
                } else {
                    h = mid-1;
                }
            } else {
                if(isEven) {
                    h = mid;
                } else {
                    l = mid+1;
                }
            }
        }
        
        return nums[h];
    }
};