
// buteforce approach
class Solution {
public:
int solve(vector<int>&nums,int i){
    int n=nums.size();
    int cost=nums[i];
    for(int j=2;j<n;j++){
        if(i+j<n){
cost=max(cost,nums[i]+solve(nums,i+j));
        }
   
    }
   return cost;
}

    int rob(vector<int>& nums) {
        int cost=INT_MIN;
        for(int i=0;i<nums.size();i++){
            cost=max(solve(nums,i),cost);
        }
        return cost;
    }
};


// optimized solution with memoization

class Solution {
public:
int solve(vector<int>&nums,int i,vector<int>&dp){
    int n=nums.size();
if(i==n-2 ||  i==n-1){
        return nums[i];
    }
    int cost=INT_MIN;
    if(dp[i]!=-1){
        return dp[i];
    }
    for(int j=2;j<n;j++){
        if(i+j<n){
cost=max(cost,nums[i]+solve(nums,i+j,dp));
        }
   
    }
   return  dp[i]=cost;
}

    int rob(vector<int>& nums) {
        int cost=INT_MIN;
        int n=nums.size();
        vector<int>dp(n,-1);
        for(int i=0;i<nums.size();i++){
            cost=max(solve(nums,i,dp),cost);
        }
        return cost;
    }
};

