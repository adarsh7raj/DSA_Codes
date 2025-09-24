
// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

// intuition:
// so the maximum product will be product of all elements if there are even number of negative elements
// if there are odd number of negative elements then we can ignore the first negative element or the last negative element
// also if there is zero in between the array we can ignore the left part and right part
// we can achieve this by calculating the prefix product and suffix product
// and taking the maximum of both the products


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int preffix=1;
        int suffix=1;
        int product=1;
        for(int i=0;i<nums.size();i++){
            if(preffix==0){
                preffix=1;
            }
            if(suffix==0){
                suffix=1;
            }
            preffix*=nums[i];
            suffix*=nums[nums.size()-i-1];
            maxi=max(maxi,max(preffix,suffix));
        }
        return maxi;
    }
};