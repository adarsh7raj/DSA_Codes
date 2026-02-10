

// dp approach : 

// TC : O(n^2) because for each index we are trying all possible jumps and for each jump we are making a
// recursive call.

// we can not use array beacuse memset works byte-by-byte, but INT_MAX is a multi-byte value.

//So memset cannot set an int array to INT_MAX correctly. INT_MAX = 2147483647 = 0x7FFFFFFF
// INT_MAX → 0x7FFFFFFF

// memset takes only the lowest byte → 0xFF

// Fills every byte with 0xFF  FF FF FF FF = -1

class Solution {
public:
int dp[10001];
int solve(vector<int>& nums, int index, vector<int>& dp) {
        int n = nums.size();
        
        // Base case: reached the end
        if (index >= n - 1) return 0;
        
        // Out of bounds
        
        
        // Memoization hit
        if (dp[index] != INT_MAX) return dp[index];
        
        // Try all possible jumps
        
        for (int i = 1; i <= nums[index] && index + i < n; ++i) {
            int next=solve(nums,index+i,dp);
             if (next != INT_MAX) {
            dp[index] = min(dp[index], 1 + next);
        }
        }
        
       
        return dp[index];
    }

    int jump(vector<int>& nums) {
         int n = nums.size();
        if (n == 1) return 0;
        vector<int> dp(n, INT_MAX);
        return solve(nums, 0, dp);
        
    }
};


// optimal solution
// TC : O(n) SC : O(1)
// we are doing l=r+1 because from l to r in previous iteration we have already calculated the farthest we 
//can jump, so we can start from r+1 in next iteration and go till the farthest we can jump from l to r.
class Solution {
public:

    int jump(vector<int>& nums) {

    int n = nums.size();
    int jumps = 0;
    int farthest=0;
    int l=0;
    int r=0;
    while(r<n-1){

        for(int i=l;i<=r;i++){
            farthest=max(farthest,nums[i]+i);
        }
        l=r+1;
        r=farthest;
        jumps++;

    }
    
    return jumps;
    }
};