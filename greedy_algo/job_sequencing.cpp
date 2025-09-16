class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
// start with maximum profit jobs and try to schedule them as late as possible before their deadlines
        // Step 0: Pair each job as (profit, deadline) for easy sorting and handling
        vector<pair<int,int>> jobs;
        for(int i=0; i<n; i++){
            jobs.push_back({profit[i], deadline[i]}); // (profit, deadline)
        }
        
        // Step 1: Sort jobs in descending order of profit
        // Why? -> We want to try the most profitable jobs first
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        // Step 2: Find the maximum deadline among all jobs
        // Why? -> Because this is the maximum time limit we need to consider
        int max_deadline = 0;
        for(auto &j : jobs){
            max_deadline = max(max_deadline, j.second);
        }

        // Step 3: Create a time slot array of size = max_deadline
        // Initially, all slots are empty (-1 means no job assigned yet)
        vector<int> slot(max_deadline, -1);
        
        int total_profit = 0;  // total profit accumulated
        int count = 0;         // number of jobs done

        // Step 4: Try to schedule each job
        for(int i=0; i<n; i++){
            int d = jobs[i].second; // deadline of current job

            // Try to place the job in the latest free slot before its deadline
            // Example: if deadline=3, we try slot 3, then 2, then 1
            for(int j=d; j>0; j--){
                if(slot[j-1] == -1){  // slot is free
                    slot[j-1] = i;    // assign job 'i' to this slot
                    total_profit += jobs[i].first; // add profit of this job
                    count++;          // increase job count
                    break;            // move to next job
                }
            }
        }

        // Return both: number of jobs done and total profit
        return {count, total_profit};
    }
};
