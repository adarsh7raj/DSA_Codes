
// Dijkstra's Algorithm for finding the shortest path in a graph
// Time Complexity: O((V + E) log V), where V is the number of vertices and E is the number of edges
// Space Complexity: O(V + E) for the adjacency list and O(V) for the
// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>result(V,INT_MAX);
        result[src]=0;
        pq.push({0,src});
        
    vector<vector<pair<int, int>>> adj(V);

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
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
};

// we can also slove this using the <vector<vector<int>>adj[v] as adjacency list


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Min-heap for shortest distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V, INT_MAX);
        result[src] = 0;
        pq.push({0, src});

        // Your required format: array of vector<vector<int>>
        vector<vector<int>> adj[V];

        // Fill adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // if undirected
        }

        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &v : adj[node]) {
                int adjNode = v[0];
                int wt = v[1];

                if (dist + wt < result[adjNode]) {
                    result[adjNode] = dist + wt;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }

        return result;
    }
};
