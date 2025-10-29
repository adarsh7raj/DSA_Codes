// brute force : 
//TC: O(n*2^n) SC: O(L) L is the length of temp vector to store each combination.
// here we are using set to avoid duplicates.
//but this will give TLE on large test cases.
// we have to skip those elements which are duplicate this will reduce the recursive calls and will not give TLE.
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
   temp.pop_back();
      find(i+1,subset,candidates,temp,target,n);
 
    
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         set<vector<int>>subset;
      
        int n=candidates.size();
        vector<int>temp;
        find(0,subset,candidates,temp,target,n);
         vector<vector<int>> result(subset.begin(), subset.end());
         return result;
    }
};

// optimal approach :
// TC: O(2^n) SC: O(L) L is the length of


// brute force : 
// this test case will not pass if used previous brute force code because of duplicates.
//[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
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
   temp.pop_back();
   int next=i+1;
   while(next<n && candidates[next]==candidates[i]){ // here we are skipping the duplicates
    next++;
   }
      find(next,subset,candidates,temp,target,n);
   
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         set<vector<int>>subset;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        cout<<n;
        vector<int>temp;
        find(0,subset,candidates,temp,target,n);
         vector<vector<int>> result(subset.begin(), subset.end());
         return result;
    }
};

//another optimal approach without using set
//TC: O(2^n*k)+nlogn  SC:Let there be M valid combinations, each of average size k. ; O(M*k)+O(n) for the recursion stack.

// Here’s what’s happening logically:

// 🔹 “Pick” Step:

// The line

// curr.push_back(candidates[i]);
// solve(..., i + 1);
// curr.pop_back();


// means you are choosing (picking) candidates[i] and exploring further with a reduced target.

// That’s the “pick” branch.

// 🔹 “Not-Pick” Step:
//After that recursive call returns,you move to the next iteration of the for loop (i++),skipping the current element.

// So, without writing a separate solve(..., i+1) call,
// the for loop itself implicitly explores the “not-pick” path — by moving on to the next element without 
//adding the current one.



class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
        if(target < 0)
            return;
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1])
                continue; //ignore duplicate elements
            curr.push_back(candidates[i]);
            solve(candidates, target-candidates[i], curr, result, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); //because we will ignore duplicate elements
        solve(candidates, target, curr, result, 0);
        return result;
    }
};