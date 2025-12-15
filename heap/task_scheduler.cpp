
// TC -> O(N) because each node is processed once and the height of the heap is log N, but N can atmost be 26 
//( number of tasks) so O(N log 26) = O(N)
// SC -> O(N) for the map and priority queue

//Greedy idea:

//Always use the task that appears the most next, so we reduce the chance of leaving it for 
//later and causing idle gaps.
// in each cycle of n+1 intervals, we try to execute as many different tasks as possible 
//Because if cooldown is n, once you execute a task, you must wait n intervals before doing it again.
// So in a block of size n+1, the same task can appear at most once.
//there must be n different tasks in a cycle in which we already executed one task.
//If there are less than n different tasks in the priority_queue, we will have idle intervals.

//If pq.empty() after this window:

// No tasks left → This was the last window.

// We don’t need to count full n+1 slots, because maybe we filled only, say, 3 tasks and no more idle needed.

// So we just add temp.size() (actual executed tasks in this last window).

// Else (still tasks left):

// We must assume we used the full n+1 length of the window including idle slots if any.

So we add n+1.



class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        priority_queue<int>pq;
        int time=0;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }

        for(auto it : mp){
            pq.push(it.second);
        }
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                
                if(!pq.empty()){
                 int freq=pq.top();
                 pq.pop();
                 freq--;
                 temp.push_back(freq);
                }
            }
                for(auto num : temp){
                    if(num>0){
                        pq.push(num);
                    }
                }
                if(pq.empty()){
                    time+=temp.size();
                }
                else{
                    time+=n+1;
                }

            
        }
        return time;

          }

          
    
};