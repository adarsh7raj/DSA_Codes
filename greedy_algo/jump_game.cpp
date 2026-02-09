

// dp solution
//TC: O(n^2) SC: O(n)

class Solution {
public:
int dp[10001];
bool solve(vector<int>& nums,int n,int i){
     if(dp[i]!=-1){
        return dp[i];
     }
    if(i>=n-1){
        return dp[i]=true;
    }
    if(nums[i]==0){
        return dp[i]=false;
    }
    
    for(int j=1;j<=nums[i];j++){
        if(solve(nums,n,i+j)){
            return dp[i]=true;
        }

    }
    return dp[i]=false;
}

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
       return  solve(nums,n,0);
    }
};

// optimal solution

//TC: O(n) SC: O(1)

// the main intution is to keep track of the last index that can be reached from the current index.
// If at any point, we find that we are at an index that is greater than the last reachable index, 
//it means we cannot jump further and we return false. If we can reach or exceed the last index of the array, 
//we return true.


// we keep moving one step at a time and soon as we find a nums[i]=0 ,we check if we have any previous index
// which can help us to jump further from this index, if not then we return false. 
//If we can jump further then we keep moving and updating the last reachable index.
class Solution {
public:

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int last_index=0;
        int i=0;
        while(i<n){
          if(i+nums[i]>=n-1){
            return true;
          }
          if(last_index<=i+nums[i]){
            last_index=i+nums[i];
          }

        
          if(nums[i]==0 && i==last_index){
            return false;
          }
          i++;
        }
return true;
    }
};