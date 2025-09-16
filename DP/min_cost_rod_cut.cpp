
// top down approach
// TC: O(n^3) SC: O(n^2)

class Solution {
public:
int dp[103][103];
int solve(vector<int>& cuts,int l,int r){
    if(r-l<2){
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int result=INT_MAX;
    for(int i=l+1;i<=r-1;i++){
       int count=cuts[r]-cuts[l]+solve(cuts,l,i) + solve(cuts,i,r);
        result=min(result,count);
    }
    return dp[l][r]=result;
}

    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
     cuts.insert(cuts.begin(),0);
     cuts.push_back(n);
     return solve(cuts,0,cuts.size()-1);
    }
};

// Bottom up approach
// TC: O(n^3) SC: O(n^2)



class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // 1. Add boundaries and sort
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // 2. Fill intervals of increasing length
        for (int len = 2; len < m; len++) {         // interval length
            for (int l = 0; l + len < m; l++) {
                int r = l + len;
                dp[l][r] = INT_MAX;
                for (int i = l + 1; i < r; i++) {   // try each cut inside
                    dp[l][r] = min(dp[l][r],
                                    dp[l][i] + dp[i][r] + (cuts[r] - cuts[l]));
                }
            }
        }

        return dp[0][m - 1];  // whole stick [0, n]
    }
};
