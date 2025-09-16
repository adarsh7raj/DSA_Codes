// Search in a Rotated Sorted Array
// You are given a sorted array that has been rotated at some unknown pivot. You need to find the index of a given target. If the target does not exist, return -1.

// Constraints:

// Array is initially sorted in ascending order.

// Array is rotated (like [4,5,6,7,0,1,2]).

// No duplicates.

// Must do it in O(log n) time.

// Example

// Input:

// nums = [4,5,6,7,0,1,2], target = 0


// Output:

// 4


// Explanation:

// The array [4,5,6,7,0,1,2] was originally [0,1,2,4,5,6,7] but rotated.

// Target 0 is at index 4.

// Intuition

// Since the array is rotated, regular binary search cannot be applied directly because the order is not strictly ascending.

// However, at least one half of the array is always sorted:

// If nums[left] <= nums[mid] → left half is sorted.

// Else → right half is sorted.

// We can check if the target lies in the sorted half and move the search accordingly:

// If target is in the sorted half → narrow search to that half.

// Else → search the other half.

// This way, we maintain O(log n) complexity.

// Algorithm

// Initialize left = 0, right = nums.size() - 1.

// While left <= right:

// Calculate mid = (left + right)/2.

// If nums[mid] == target, return mid.

// Check which half is sorted:

// Left half sorted: nums[left] <= nums[mid]

// If target lies between nums[left] and nums[mid], move right = mid - 1.

// Else, move left = mid + 1.

// Right half sorted:

// If target lies between nums[mid] and nums[right], move left = mid + 1.

// Else, move right = mid - 1.

// If target not found, return -1.



class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
    
            while (left <= right) {
                int mid = (left + right) / 2;
    
                if (nums[mid] == target)
                    return mid;
    
                // Left half is sorted
                if (nums[left] <= nums[mid]) {
                    if (nums[left] <= target && target < nums[mid])
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
                // Right half is sorted
                else {
                    if (nums[mid] < target && target <= nums[right])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
    
            return -1;
        }
    };
    