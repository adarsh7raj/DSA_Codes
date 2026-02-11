
//TC:O(n) SC:O(n)

// we can slightly improve the without using the ans 2d vector
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=newInterval[0]){
                 ans.push_back(newInterval);   
                 newInterval={-1,-1};
            }
            ans.push_back(intervals[i]);
        }
      if(newInterval[0]!=-1){
        ans.push_back(newInterval);
      }
     vector<vector<int>>result;
     vector<int>last=ans[0];
     for(int i=1;i<ans.size();i++){

        while(i<ans.size() && last[1]>=ans[i][0]){
              if(last[1]>=ans[i][1]){
                i++;
              }
              else {
                last={last[0],ans[i][1]};
                i++;
              }
        }
        if(i<ans.size()){
        result.push_back(last);
        last=ans[i];
        }
       
     }
     result.push_back(last);
     return result;
    }
};

// slightly improved code :


ublic:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> result;
        
        while(i < intervals.size()) {
            if(intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                break;
            } else {
                //Overlap : merge them
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        
        result.push_back(newInterval);
        while(i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};
