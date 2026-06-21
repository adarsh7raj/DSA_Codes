
// TC :O(n^2) sc: O(n)
class Solution {
public:
    int dp[2501][2501];

    int solve(vector<int>& arr, int i, int pv) {
        if(i >= arr.size()) {
            return 0;
        }

        if(pv != -1 && dp[i][pv] != -1) { // pv is  previous greatest element index
            return dp[i][pv];
        }

        int take = 0;
        if(pv == -1 || arr[i] > arr[pv]) {
            take = 1 + solve(arr, i + 1, i);
        }

        int not_take = solve(arr, i + 1, pv);
        
        if(pv != -1) {
            dp[i][pv] = max(take, not_take);
        }

        return max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};


//using tabulation TC: O(n^2) sc: O(n^2):

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n + 1,
                               vector<int>(n + 1, 0));

        for(int i = n - 1; i >= 0; i--) {

            for(int prev = i - 1; prev >= -1; prev--) {

                int notTake = dp[i + 1][prev + 1];

                int take = 0;

                if(prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + dp[i + 1][i + 1];
                }

                dp[i][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};

//using space optimization TC: O(n^2) sc: O(n):

for(int i=0;i<n;i++){
    dp[i]=1;

    for(int j=0;j<i;j++){
        if(nums[j] < nums[i]){
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
}
// using space optimization TC: O(n^2) sc: O(n):

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            for(int prev = i - 1; prev >= -1; prev--) {

                int notTake = next[prev + 1];

                int take = 0;

                if(prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + next[i + 1];
                }

                curr[prev + 1] = max(take, notTake);
            }

            next = curr;
        }

        return next[0];
    }
};

// using binary search TC: O(nlogn) SC: O(n)

class Solution {
public:
    
int lengthOfLIS(vector<int>& nums) {
    vector<int>temp;
    temp.push_back(nums[0]);

    for (int i=0;i<nums.size();i++) {
        // Find the first element in sub >= num
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
        }
        else{
            auto it=lower_bound(temp.begin(),temp.end(),nums[i]);
            *it=nums[i];
        }
    }
    return temp.size();
}
};
