// brute force approach : O(n*3^L):  L (≤ n) is the cost to copy a valid temp vector into the set.
// If we are using this approach where we making 3 recursive calls at each step, then we have to use set<vector<int>>
// to avoid duplicates.
// 
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
    find(i+1,subset,candidates,temp,target-candidates[i],n);// take the element and move to next index
    
    find(i,subset,candidates,temp,target-candidates[i],n);// take the element and stay on same index
    temp.pop_back();
    find(i+1,subset,candidates,temp,target,n);// not take the element and move to next index

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         set<vector<int>>subset;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int>temp;
        find(0,subset,candidates,temp,target,n);//
         vector<vector<int>> result(subset.begin(), subset.end());
         return result;
    }
};


// better appraoch : O(2^n):
// here we are making only 2 recursive calls at each step, so no need to use set to avoid duplicates.
class Solution {
public:
void find(int i,vector<vector<int>>& subset,vector<int>&candidates,vector<int> &temp,int target,int n){
    if(target==0){
        subset.push_back(temp);
        return ;
    }
    if(target<0 || i>=n ){
        return;
    }
    temp.push_back(candidates[i]);
     find(i,subset,candidates,temp,target-candidates[i],n);// take the element and stay on same index
   temp.pop_back();
      find(i+1,subset,candidates,temp,target,n);// not take the element and move to next index

    //   temp.push_back(candidates[i]);
    // find(i+1,subset,candidates,temp,target-candidates[i],n);
    // temp.pop_back();
    
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>>subset;
       // sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int>temp;
        find(0,subset,candidates,temp,target,n);
        // vector<vector<int>> result(subset.begin(), subset.end());
         return subset;
    }
};