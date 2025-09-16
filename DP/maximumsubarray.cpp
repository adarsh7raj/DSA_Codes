// optimal solution TC: O(n) SC: O(1)
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


//modified kadane's algorithm TC: O(n) SC: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    
    int maxProd = nums[0];  // Final result
    int currMax = nums[0];  // Current max ending here
    int currMin = nums[0];  // Current min ending here (important for negative numbers)

    for (int i = 1; i < n; i++) {
        int temp = currMax;
        currMax = max({nums[i], currMax * nums[i], currMin * nums[i]});
        currMin = min({nums[i], temp * nums[i], currMin * nums[i]});
        maxProd = max(maxProd, currMax);
    }

    return maxProd;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum Product Subarray: " << maxProduct(nums) << endl;
    return 0;
}
