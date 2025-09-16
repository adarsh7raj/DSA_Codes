
// Generally next permutationn elements are tend to longest permutation this approach will take 3*O(n) time

// eg : arr[]=2154300
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int index = -1;
            int n = nums.size();
    
            // Step 1: Find the first decreasing element from the right we will find the breaking point before the breaking point the elements are in decreasing order.
            for (int i = n - 1; i >= 0; i--) {
                if (nums[i] > nums[i - 1]) {
                    index = i;
                    break;
                }
            }
    
            // Step 2: If no such element is found, reverse the array (last permutation)
            if (index == -1) {
                reverse(nums.begin(), nums.end());
                return;
            }
    
            // Step 3: Find the next larger element and swap
            for (int j = n - 1; j > index; j--) {
                if (nums[j] > nums[index]) {
                    swap(nums[index], nums[j]);
                    break;
                }
            }
    
            // Step 4: Reverse the suffix after the swapped element
            reverse(nums.begin() + index + 1, nums.end());
        }
    };
    

    // brute approach will be :  TC:O(n!*n)
    // 1. First find all the possible permutations 
    // 2. Second do linear search to find the element and take the next element.