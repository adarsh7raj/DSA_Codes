
// memoization 
//TC: O(n*m*m) where n is number of rows and m is number of columns
//SC: O(n*m*m) for dp array and O(n) for recursion stack space
class Solution {
public:
int solve(vector<vector<int>>&g,int i,int j,int k,int n,int m,  vector<vector<vector<int>>>& dp){
if(i>=n || j>=m || j<0 || k<0 || k>=m){
    return INT_MIN;
}
if(i==n-1){
   if(j==k){
    return g[i][j];
   }
    return g[i][j] + g[i][k];
}
int maxi=INT_MIN;
if(dp[i][j][k]!=-1){
    return dp[i][j][k];
}
for(int idx=-1;idx<=1;idx++ ){

    for(int jdx=-1;jdx<=1;jdx++){
    maxi=max(solve(g,i+1,j+idx,k+jdx,n,m,dp),maxi);

    }
}

if(j==k){
    return dp[i][j][k] =maxi+g[i][j];
}
return dp[i][j][k]= maxi+g[i][j]+g[i][k];

}
    int cherryPickup(vector<vector<int>>& g){
     int n=g.size();
     int m=g[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return  solve(g,0,0,m-1,n,m,dp);
    }
};