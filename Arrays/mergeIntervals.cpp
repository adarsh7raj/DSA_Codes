//optimal solution : 
// TC : O(nlogn)+O(n) SC : O(n)
class Solution {
public:
// already sorted
//ans=[[1,6]]
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     vector<vector<int>>ans;
     int n=intervals.size();
     sort(intervals.begin(),intervals.end());
     int start=intervals[0][0];
     int end=intervals[0][1];
   
     for(int i=1;i<n;i++){
//merge intervals(overlapping):
 if(intervals[i][0]<=end){
    end=max(end,intervals[i][1]);
 }
 // non overlapping
 else{
    ans.push_back({start,end});
    start=intervals[i][0];
    end=intervals[i][1];
 }
     }
     ans.push_back({start,end});
     return ans;
    }
};
