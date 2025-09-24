  //This question might work for both  subarray sum equal to k and subarray sum equal to zero;
// find the length of the longest subarray whose sum equal to k
//brute force O(n^2): 
class Solution {
    public:
        int maxLen(vector<int>& arr) {
            int n = arr.size();
            int longest = 0;
            vector<vector<int>> ans;
            if (n == 0) {
                return 0;
            }
            for (int i = 0; i < n; i++) {
                int result = 0;
                for (int j = i; j < n; j++) {
                    result += arr[j];
                    if (result == 0) {
                        longest = max(longest, (j - i + 1));
                    }
                }
            }
            return longest;
        }
    };
    




//better approach : O(nlogn)

// Why m[0]++ is needed

// m (the map) stores prefix sums and how many times each prefix sum has occurred.

// Prefix sum: sum[i] = arr[0] + arr[1] + ... + arr[i]

// Suppose we want a subarray whose sum = k.

// Let the current prefix sum be sum[i].

// We look for a previous prefix sum rem = sum[i] - k.

// If rem exists in the map, it means the subarray after that prefix sum to the current index sums to k.

// But what if the subarray starts from index 0?

// Then the prefix sum itself equals k: sum[i] = k

// For this case, rem = sum[i] - k = 0

// So, we need to pretend that prefix sum 0 occurred once before the array starts, so the map lookup works.

// Hence we do:

// m[0] = 1; // there is 1 "empty subarray" sum = 0 before the array starts


// Without this, the first subarray starting at index 0 that sums to k would not be counted.

// 2️⃣ What if(sum == k) does

// It explicitly checks if the current prefix sum itself is equal to k.

// This corresponds to a subarray starting from index 0.

// Example:

// arr = [1, 2, 3], k = 3


// Prefix sums: [1, 3, 6]

// When i = 1, sum = 3 → this is exactly k

// So, the subarray [1, 2] should be counted.

// Two ways to handle this:

// Using if(sum == k) count++; — direct check for subarrays starting at index 0.

// Using m[0] = 1 before the loop — automatically handled when you do:

// int rem = sum - k; // rem = 3 - 3 = 0
// count += m[rem];   // m[0] = 1, so count increments


// ✅ Both methods handle the same scenario. You don’t need both if you correctly initialize m[0] = 1.
    class solution {
        public :
        int maxLen(vector<int>& arr) {
            int n=arr.size();
            map<int>prefix_arr;
            int sum=0;
            int longest=0;
            for(int i=0;i<n;i++){
                sum=sum+arr[i];
                if(sum==0){  // instead of this we can also do m[0]++ before the loop starts.
                    longest=max(longest,i+1);
                }
                int rem=sum-0;
                if(prefix_arr.count(rem)){
                   int length=i-prefix_arr[rem];
                   longest=max(longest,length);


                } // add this extra condition to make sure if zero is present.
                if(!prefix_arr.count(sum)){
                    prefix_arr[sum]=i;
                }
            }
        }
    }

    //optimal solution :  O(2n) sliding window technique.

    class Solution {
        public:
            int subarraySum(vector<int>& arr,int k) {
                int n = arr.size();
                int left=0;
                int right=0;
                int longest=0;
                int sum=0;
                while(right<n){
                       while(left<=right && sum>k){
                sum=sum-arr[left];
                left++;
               }
                     sum=sum+arr[right];
                     if(sum==k){
                        longest=max(longest,right-left+1);
                    }
                        right++;
                   
                    
            
                }
                return longest;
            }
        };
        