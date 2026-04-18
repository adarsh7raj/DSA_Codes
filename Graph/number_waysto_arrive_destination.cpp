
//TC : O((V + E) log V)
//SC : O(V + E) for the adjacency list and O(V) for the result and ways vector

class Solution {
public:
int M=1e9+7;
  int  dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
       priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long>result(V,LLONG_MAX);
        vector<int>ways(V,0);
        result[src]=0;
        ways[0]=1;
        pq.push({0,src});
        
    vector<vector<pair<int, long long>>> adj(V);

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
        while(!pq.empty()){
            long long dist=pq.top().first;
            int node =pq.top().second;
            pq.pop();
            for(auto v: adj[node]){
                int adjNode=v.first;
                long long  wt=v.second;
              
                if(dist+wt<result[adjNode]){
                    result[adjNode]=dist+wt;
                    pq.push({dist+wt,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(dist+wt==result[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%M;
                }
            }
        }
        return ways[V-1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        return dijkstra(n,roads,0);
        
    }
};