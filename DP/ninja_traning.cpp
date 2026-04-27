
//overall time complexity is O(n*4*3) and space complexity is O(n*4)+O(n) for recursion stack
class Solution {
  public:
   int solve(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp,int n){
       if(i>=n){
           return 0;
       }
       int skill=-1;
       if(dp[i][j]!=-1){
           return dp[i][j];
       }
     for(int k=0;k<3;k++){
         if(j!=k){
              skill=max(skill,mat[i][k]+solve(i+1,k,mat,dp,n));
         }
        
     }
     return dp[i][j]=skill;
      
   }
  
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return solve(0,3,mat,dp,n);
    }
};

//optimal tabulation:
class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(3, 0));

        // 🔹 Base case (day 0)
        for (int task = 0; task < 3; task++) {
            dp[0][task] = mat[0][task];
        }

        // 🔹 Fill from day 1 → n-1
        for (int i = 1; i < n; i++) {
            for (int task = 0; task < 3; task++) {

                int maxi = 0;

                for (int prev = 0; prev < 3; prev++) {
                    if (prev != task) {
                        maxi = max(maxi, dp[i-1][prev]);
                    }
                }

                dp[i][task] = mat[i][task] + maxi;
            }
        }

        // 🔹 Final answer = best of last day
        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};


//optimal space optimized:



class Solution {
  public:

  
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
       vector<int> prev = mat[0];
       int n=mat.size();
for (int i = 1; i < n; i++) {
    vector<int> curr(3);

    for (int task = 0; task < 3; task++) {
        int maxi = 0;

        for (int prevTask = 0; prevTask < 3; prevTask++) {
            if (prevTask != task) {
                maxi = max(maxi, prev[prevTask]);
            }
        }

        curr[task] = mat[i][task] + maxi;
    }

    prev = curr;
}

return max({prev[0], prev[1], prev[2]});
    }
};