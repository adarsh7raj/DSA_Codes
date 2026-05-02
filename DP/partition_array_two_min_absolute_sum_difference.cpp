

// this will give tle because of large constraints
// no memoization because of large constraints
class Solution {
public:

 
    bool solve(int i,
               int target,
               vector<int>& nums,
               int curr_sum,int taken) {

        // target reached
        if(curr_sum == target && taken ==nums.size()/2) {
            return true;
        }

        // end of array
        if(i >= nums.size()) {
            return false;
        }

        // memoization
        // if(dp[i].count(curr_sum)) {
        //     return dp[i][curr_sum];
        // }

        // take
        bool take = solve(i + 1,
                          target,
                          nums,
                          curr_sum + nums[i],
                          taken+1);

        // not take
        bool not_take = solve(i + 1,
                              target,
                              nums,
                              curr_sum,
                              taken);

        return  (take || not_take);
    }
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
         for(int i=0;i<n;i++){
       sum+=nums[i];
         } 
         int sum1=ceil(sum/2.0);
       
         while(1){
             
            int sum2=sum-sum1;
 //vector<unordered_map<int,int>> dp(nums.size());
           
            if(solve(0,sum1,nums,0,0) && sum1!=0){
                return abs(sum1-sum2);
            }
           sum1--;
         }
         return 0;
    }
};


// optimal solution  using meet in middle algo , binary search , sorting and two pointer approach,bit manipulation

// Step-by-Step Explanation
// Step 1
// int n = nums.size() / 2;

// If array size = 6:

// n = 3

// We need:

// one subset with 3 elements
// another subset with 3 elements
// Step 2
// vector<int> left(nums.begin(), nums.begin() + n);
// vector<int> right(nums.begin() + n, nums.end());

// Split array into 2 halves.

// Example:

// nums = [1,2,3,4,5,6]

// Then:

// left  = [1,2,3]
// right = [4,5,6]
// Step 3
// int total = accumulate(nums.begin(), nums.end(), 0);

// Find total sum.

// Example:

// 1+2+3+4+5+6 = 21
// Step 4
// vector<vector<int>> leftSums(n + 1);
// vector<vector<int>> rightSums(n + 1);

// Very important.

// Meaning
// leftSums[k]

// stores:

// all possible subset sums
// using exactly k elements from left half.

// Similarly:

// rightSums[k]
// Example

// Suppose:

// left = [1,2,3]

// Then:

// k	Possible sums
// 0	[0]
// 1	[1,2,3]
// 2	[3,4,5]
// 3	[6]

// Because:

// 1+2=3
// 1+3=4
// 2+3=5
// Step 5
// for(int mask = 0; mask < (1 << n); mask++)

// This generates ALL subsets.

// Why (1 << n)?

// If:

// n = 3

// then:

// 1<<3=8

// meaning:

// 8 masks
// 8 subsets

// because:

// 2
// 3
// =8

// Binary Representation Trick

// Each bit tells:

// take element
// or not

// Example:

// mask = 5

// Binary:

// 101

// Meaning:

// take index 0
// skip index 1
// take index 2
// Step 6
// int cnt = 0;
// int sum = 0;

// For current subset:

// cnt = number of chosen elements
// sum = subset sum
// Step 7
// for(int i = 0; i < n; i++)

// Check every bit.

// Step 8
// if(mask & (1 << i))

// Check whether ith bit is ON.

// Example

// Suppose:

// mask = 5 = 101

// Check:

// mask & (1<<0)

// TRUE.

// So take element 0.

// Step 9
// cnt++;
// sum += left[i];

// Update:

// chosen count
// subset sum
// Step 10
// leftSums[cnt].push_back(sum);

// Store this subset sum grouped by chosen element count.

// Same Process for Right Half
// rightSums

// stores all subset sums from right half.

// Step 11
// sort(rightSums[i].begin(), rightSums[i].end());

// Needed for binary search.

// Why Binary Search?

// We want sum closest to:

// total/2

// Efficient searching needed.

// Step 12
// int ans = INT_MAX;

// Stores minimum difference.

// Step 13
// for(int k = 0; k <= n; k++)

// Suppose we choose:

// k elements from left

// Then we MUST choose:

// n−k

// from right.

// Because total chosen must be exactly n.

// Example

// Need total chosen = 3.

// If:

// 1 taken from left

// then:

// 2 must come from right.
// Step 14
// for(int leftSum : leftSums[k])

// Try every possible left-half subset sum.

// Step 15
// int need = n - k;

// Number of elements required from right half.

// Step 16
// int target = total / 2 - leftSum;

// Critical intuition.

// We want:

// leftSum+rightSum≈total/2

// So:

// rightSum≈total/2−leftSum

// This is target.

// Step 17
// auto& vec = rightSums[need];

// All right-half sums using exactly need elements.

// Step 18
// auto it = lower_bound(vec.begin(), vec.end(), target);

// Binary search.

// Find first value:

// greater than or equal to target.
// Why lower_bound?

// We need closest value to target.

// Closest can be:

// current iterator
// previous iterator
// Step 19
// if(it != vec.end())

// Check current candidate.

// Step 20
// int chosen = leftSum + *it;

// Total chosen subset sum.

// Step 21
// int other = total - chosen;

// Remaining subset sum.

// Step 22
// ans = min(ans, abs(chosen - other));

// Update minimum difference.

// Step 23
// if(it != vec.begin())

// Check previous value too.

// Because previous may be closer.

// Final Return
// return ans;

// Minimum possible difference.

class Solution {
public:

    int minimumDifference(vector<int>& nums) {
         int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        int total = accumulate(nums.begin(), nums.end(), 0);

        // leftSums[k] = all subset sums taking k elements from left
        // rightSums[k] = all subset sums taking k elements from right

        vector<vector<int>> leftSums(n + 1);
        vector<vector<int>> rightSums(n + 1);

        // Generate subset sums for left half
        for(int mask = 0; mask < (1 << n); mask++) {

            int cnt = 0;
            int sum = 0;

            for(int i = 0; i < n; i++) {

                if(mask & (1 << i)) {
                    cnt++;
                    sum += left[i];
                }
            }

            leftSums[cnt].push_back(sum);
        }

        // Generate subset sums for right half
        for(int mask = 0; mask < (1 << n); mask++) {

            int cnt = 0;
            int sum = 0;

            for(int i = 0; i < n; i++) {

                if(mask & (1 << i)) {
                    cnt++;
                    sum += right[i];
                }
            }

            rightSums[cnt].push_back(sum);
        }

        // Sort right sums for binary search
        for(int i = 0; i <= n; i++) {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        int ans = INT_MAX;

        // Choose k elements from left
        for(int k = 0; k <= n; k++) {

            // Need n-k from right
            for(int leftSum : leftSums[k]) {

                int need = n - k;

                // We want:
                // chosenSum as close as possible to total/2

                int target = total / 2 - leftSum;

                auto& vec = rightSums[need];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                // Check current iterator
                if(it != vec.end()) {

                    int chosen = leftSum + *it;

                    int other = total - chosen;

                    ans = min(ans, abs(chosen - other));
                }

                // Check previous iterator
                if(it != vec.begin()) {

                    --it;

                    int chosen = leftSum + *it;

                    int other = total - chosen;

                    ans = min(ans, abs(chosen - other));
                }
            }
        }

        return ans;
    }
};