
// TC : O(n~log n) SC: O(n)
class Solution {
public:
    struct Job {
        int start, end, profit;
    };

    int solve(int i, vector<Job>& jobs, vector<int>& dp) {
        if (i >= jobs.size()) return 0;
        if (dp[i] != -1) return dp[i];

        // Skip current job
        int not_take = solve(i + 1, jobs, dp);

        // Take current job
        int nextIndex = findNextJob(i, jobs);
        int take = jobs[i].profit + solve(nextIndex, jobs, dp);

        return dp[i] = max(take, not_take);
    }

    int findNextJob(int i, vector<Job>& jobs) {
        int lo = i + 1, hi = jobs.size() - 1, ans = jobs.size();
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (jobs[mid].start >= jobs[i].end) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a.start < b.start;
        });

        vector<int> dp(n, -1);
        return solve(0, jobs, dp);
    }
};
