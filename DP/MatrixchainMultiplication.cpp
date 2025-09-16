// TC : O(N^3) because O(n^2) due to traversing each element of dp array and O(N) for the for loop
// SC : O(N^2) + O(N) for recursion stack space


// dp[i][j] is defined as: minimum cost to multiply matrices from Mᵢ to Mⱼ

//To multiply the entire chain: from M₁ to Mₙ → indices 1 to n-1 in the dp table
class Solution {
  public:
  int dp[100][100];
  int solve(int i,int j,vector<int>& arr){
      if(i==j){
          return 0;
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      int mini=INT_MAX;
      for(int k=i;k<j;k++){
          int steps= arr[i-1]*arr[k]*arr[j] + solve(i,k,arr)+solve(k+1,j,arr);
          mini=min(mini,steps);
      }
      return dp[i][j]=mini;
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size()-1;
        memset(dp,-1,sizeof(dp));
        return solve(1,n,arr);
    }
};


// bottom up approach


class Solution {
  public:

    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        int dp[n][n];
    
     for(int i=0;i<arr.size();i++){
         dp[i][i]=0;
     }
     for(int i=n-1;i>=1;i--){
         for(int j=i+1;j<n;j++){
             int mini=INT_MAX;
              for(int k=i;k<j;k++){
          int steps= arr[i-1]*arr[k]*arr[j] + dp[i][k]+dp[k+1][j];
          mini=min(mini,steps);
      }
      dp[i][j]=mini;
         }
     }
        return dp[1][n-1];
    }
};