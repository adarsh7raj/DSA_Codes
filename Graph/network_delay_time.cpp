
// just find the maximum time taken of all the minimum time taken to reach each node from the source node, if any node is not reachable from the source node then return -1
class Solution {
public:

   vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>result(V+1,INT_MAX);
        
        result[src]=0;
        pq.push({0,src});
        
    vector<vector<pair<int, int>>> adj(V+1);

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
       
    }
        while(!pq.empty()){
            int dist=pq.top().first;
            int node =pq.top().second;
            pq.pop();
            for(auto v: adj[node]){
                int adjNode=v.first;
                int wt=v.second;
                if(dist+wt<result[adjNode]){
                    result[adjNode]=dist+wt;
                    pq.push({dist+wt,adjNode});
                }
            }
        }
        return result;
    }
   
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>result=dijkstra(n,times,k);
         int minimum_time=0;
        for(int i=1;i<=n;i++){
            if(result[i]==INT_MAX){
                return -1;
            }
            minimum_time=max(minimum_time,result[i]);
        }
        return minimum_time;
    }
};