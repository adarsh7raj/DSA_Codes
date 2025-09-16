// brute force approach : TC : (2^n):
#include <bits/stdc++.h> 

bool find(vector<int>arr,int i,int n,int sum){
    if(sum==0){
        return 1;
    }
    if(i==n || sum<0){
        return 0;
    }
    return find(arr,i+1,n,sum) || find(arr,i+1,n,sum-arr[i]);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return find(arr,0,n,k);
}

// optimal solution using DP : O(sum*k):
#include <bits/stdc++.h>
using namespace std;

bool find(int i, int sum, vector<int> &arr, vector<vector<int>> &dp) {
    if (sum == 0) return true;
    if (i == arr.size()) return false;

    if (dp[i][sum] != -1) return dp[i][sum];

    bool notPick = find(i + 1, sum, arr, dp);
    bool pick = false;
    if (arr[i] <= sum)
        pick = find(i + 1, sum - arr[i], arr, dp);

    return dp[i][sum] = pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return find(0, k, arr, dp);
}
