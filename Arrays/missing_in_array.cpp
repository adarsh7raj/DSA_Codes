//TC: O(N)
//SC: O(1)

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long n=arr.size()+1;
        long long n_sum=n*(n+1)/2;
        long long arr_sum=0;
        for(int  i=0;i<arr.size();i++){
            arr_sum+=arr[i];
        }
        return (int) (n_sum-arr_sum);
    }
};

//we can also use xor operation to find the missing number
//TC: O(N)
//SC: O(1)

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
       int n = arr.size() + 1;
    int ans = 0;

    for (int i = 1; i <= n; i++) ans ^= i;
    for (int x : arr) ans ^= x;

    return ans;
    }
};