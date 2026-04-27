
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
//dp[i] = maximum money you can collect starting from index i, assuming you MUST pick nums[i]
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



// another approach : 


class Solution {
public:
int solve(vector<int>&nums,int i,vector<int>&dp){
    int n=nums.size();
  if(i>=n){
    return 0;
  }
 if(dp[i]!=-1){
    return dp[i];
 }
  int take=nums[i]+solve(nums,i+2,dp);
  int not_take=solve(nums,i+1,dp);
  return dp[i]=max(take,not_take);
}

    int rob(vector<int>& nums) {
        int cost=INT_MIN;
        int n=nums.size();
        vector<int>dp(n,-1);
        
        return solve(nums,0,dp);
    }
};


//bottom up approach
//t[i] = max profit till house i
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        vector<int> t(n+1);
  
        
        t[0] = 0;
        t[1] = nums[0];
        
        for(int i = 2; i<=n; i++) {
            
            int skip  = t[i-1];
            int steal = nums[i-1] + t[i-2];
          
            t[i] = max(skip, steal); //max(skip, steal)
            /*
                SKIP  : If we skip this house,  then we have money till previous house  =  t[i-1]
                STEAL : If we steal this house, then we can't take prev profit, we can take till (i-2)th house profit = t[i-2]
            */
        }
        
        return t[n];
        
    }
};


// space optimized approach


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prevPrev = 0;
        int prev     = nums[0];
        
        for(int i = 2; i<=n; i++) {
            int skip = prev;
            
            int take = nums[i-1] + prevPrev;
                
            int temp = max(skip, take);
            
            prevPrev = prev;
            prev     = temp;
        }
        
        return prev;
    }
};