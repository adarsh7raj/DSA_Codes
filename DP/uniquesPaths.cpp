//brute force recursion  approach : but this will give TLE;
class Solution {
    public:
        int uniquePaths(int m, int n) {
            return paths(0,0,m,n);
    };
    int paths(int i,int j , int m , int n){
        if(i==(m-1)&&j==(n-1)){
            return 1;
        }
        if(i>=m||j>=n){
            return 0;
        }
        else{
            return paths(i+1,j,m,n)+paths(i,j+1,m,n);
        }
    }
    };


    //optimal solution using : memoization : time complexity is O(m*n) and space complexity is O(m*n)+O(m+n) for recursion stack


class Solution {    public:

        int paths(int i,int j , int m , int n,vector<vector<int>>&dp){
            if(i==(m-1)&&j==(n-1)){
                return 1;
            }
            if(i>=m||j>=n){
                return 0;
            }
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            else{
                return dp[i][j]=paths(i+1,j,m,n,dp)+paths(i,j+1,m,n,dp);
            }
        }
        int uniquePaths(int m, int n) {
            vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
            return paths(0,0,m,n,dp);   

// optimal solution using : tabulation : time complexity is O(m*n) and space complexity is O(m*n)
class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
         dp[0][0]=0;
         for(int i=0;i<m;i++){
            dp[i][0]=1;

         }
         for(int i=0;i<n;i++){
            dp[0][i]=1;
         }

  for(int i=1;i<m;i++){
    for(int j=1;j<n;j++){
        dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
  }
  return dp[m-1][n-1];
    }
};



//optimal solution: 
class Solution {
    public:
      class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
         dp[0][0]=1;
         for(int i=1;i<m;i++){
            dp[i][0]=1;

         }
         for(int i=1;i<n;i++){
            dp[0][i]=1;
         }

  for(int i=1;i<m;i++){
    for(int j=1;j<n;j++){
        dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
  }
  return dp[m-1][n-1];
    }
};

    };