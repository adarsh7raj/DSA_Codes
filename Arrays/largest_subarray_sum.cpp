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
    class solution {
        public :
        int maxLen(vector<int>& arr) {
            int n=arr.size();
            map<int>prefix_arr;
            int sum=0;
            int longest=0;
            for(int i=0;i<n;i++){
                sum=sum+arr[i];
                if(sum==0){
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
        