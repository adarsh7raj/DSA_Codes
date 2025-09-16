// brute force approach : TC n(2^n); n for subset.insert(temp) and 2^n for each recursive call .

class Solution {
public:
void subSet(int i,vector<int>& arr,set<vector<int>>& subset,vector<int>temp,int n){
    if(i>=n){
        subset.insert(temp);
        return;
    }
    temp.push_back(arr[i]);
    subSet(i+1,arr,subset,temp,n);
    temp.pop_back();
    subSet(i+1,arr,subset,temp,n);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>subset;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>temp;
        subSet(0,nums,subset,temp,n);
         vector<vector<int>> result(subset.begin(), subset.end());
         return result;
    }
};  