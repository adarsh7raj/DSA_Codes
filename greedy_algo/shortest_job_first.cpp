

// User function Template for C++

//Back-end complete function Template for C++
//TC: O(n log n) + O(n * max_deadline) in worst case
class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        long long sum=0;
        long long  prefix_sum=0;
        int n=bt.size();
        sort(bt.begin(),bt.end());
        for(int i=0;i<n-1;i++){
            prefix_sum+=bt[i];
            sum+=prefix_sum;
        }
        return sum/n;
        
    }
};