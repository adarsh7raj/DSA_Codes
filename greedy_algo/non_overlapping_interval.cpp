
// brute force approach : O(n^2)  TLE

class Solution {
public:
    int mini;

    // check if selected intervals overlap
    bool is_overlapping(vector<vector<int>>& temp) {
        for(int i = 1; i < temp.size(); i++) {
            if(temp[i][0] < temp[i-1][1])
                return true;
        }
        return false;
    }

    void solve(vector<vector<int>>& intervals, int i, 
               vector<vector<int>>& temp) {
        
        if(i == intervals.size()) {   // base case
            if(!is_overlapping(temp)) {
                int removed = intervals.size() - temp.size();
                mini = min(mini, removed);
            }
            return;
        }

        // Take interval
        temp.push_back(intervals[i]);
        solve(intervals, i+1, temp);

        // Backtrack
        temp.pop_back();

        // Don't take interval
        solve(intervals, i+1, temp);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        mini = INT_MAX;
        vector<vector<int>> temp;

        solve(intervals, 0, temp);

        return mini;
    }
};




// optimal solution : O(nlogn) + O(n) SC : O(1)

class Solution {
public:

    // check if selected intervals overlap
    // we can solve it by sorting the intervals by their end time .

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1]; });
        int n=intervals.size();

        if(n==0){
            return 0;
        }
        int start=intervals[0][0];
        int end=intervals[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(end>intervals[i][0]){
                count++;
            }
            else{
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        return count;
    }
};

//we can also solve it by sorting the intervals by their start time

 int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int n = intervals.size(); 
        
        int count = 0;
        int i = 0, j = 1;
        
        while(j < n) {
            vector<int> curr_interval = intervals[i];
            vector<int> next_interval = intervals[j];
            
            int curr_start = curr_interval[0];
            int curr_end   = curr_interval[1];
            
            int next_start = next_interval[0];
            int next_end   = next_interval[1];
            
            if(curr_end <= next_start) { //SAFE
                i = j;
                j++;
            } else if(curr_end <= next_end) {
                /*
                    GREEDY : Remove next interval as it has high chances to
                             overlap with future intervals
                */
                j++;
                count++;
            } else if(curr_end > next_end) {
                /*
                    GREEDY : Remove current interval as it has high chances to
                             overlap with future intervals
                */
                i = j;
                j++;
                count++;
            }
        }

        return count;

    }
};



