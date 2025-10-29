
// brute force approach : 

class Solution {
public:
void solve(int i,int k,int n,int sum,vector<int>temp,set<vector<int>>& ans){
    if(sum==n && temp.size()==k){
        ans.insert(temp);
        return;
    }
   
    if(i>9){
        return;
    }
    temp.push_back(i);
    solve(i+1,k,n,sum+i,temp,ans);
    temp.pop_back();
    solve(i+1,k,n,sum,temp,ans);

}
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>>ans;
        vector<int>temp;
        solve(1,k,n,0,temp,ans);
        
        vector<vector<int>>result;
        for(auto it:ans){
           
            result.push_back(it);
        }
        return result;
    }
};




