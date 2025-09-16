// brute force approach : O(n*3^L):  L (≤ n) is the cost to copy a valid temp vector into the set.

class Solution {
public:
void find(int i,set<vector<int>>& subset,vector<int>&candidates,vector<int> &temp,int target,int n){
    if(target==0){
        subset.insert(temp);
        return ;
    }
    if(target<0 || i>=n ){
        return;
    }
    temp.push_back(candidates[i]);
    find(i+1,subset,candidates,temp,target-candidates[i],n);
    
    find(i,subset,candidates,temp,target-candidates[i],n);
    temp.pop_back();
    find(i+1,subset,candidates,temp,target,n);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         set<vector<int>>subset;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int>temp;
        find(0,subset,candidates,temp,target,n);
         vector<vector<int>> result(subset.begin(), subset.end());
         return result;
    }
};


// better appraoch : O(2^n):

class Solution {
public:
void find(int i,set<vector<int>>& subset,vector<int>&candidates,vector<int> &temp,int target,int n){
    if(target==0){
        subset.insert(temp);
        return ;
    }
    if(target<0 || i>=n ){
        return;
    }
    temp.push_back(candidates[i]);
     find(i,subset,candidates,temp,target-candidates[i],n);
   temp.pop_back();
      find(i+1,subset,candidates,temp,target,n);
    //find(i+1,subset,candidates,temp,target-candidates[i],n);
    
   
 
  

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         set<vector<int>>subset;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int>temp;
        find(0,subset,candidates,temp,target,n);
         vector<vector<int>> result(subset.begin(), subset.end());
         return result;
    }
};