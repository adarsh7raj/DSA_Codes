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

