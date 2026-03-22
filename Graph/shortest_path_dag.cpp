


// User function Template for C++
// This is not optimal solution we might visit a node multiple times and relax the same node multiple times, 
// TC : O(V + E) for BFS + O(V) for updating unreachable nodes = O(V + E) in average case. In 
//worst case, if all edges have the same weight, it can degrade to O(V*E) due to the queue operations.
// SC : O(V+E) for adjacency list + O(V) for visited + O
class Solution {
  public:
  
  vector<int> bfs(vector<vector<pair<int,int>>>adj,int V){
      queue<int>q;
      vector<int>dist(V,1e9);
      q.push(0);
      dist[0]=0;
      while(!q.empty()){
          int node=q.front();
         
          q.pop();
          for(pair<int,int>v:adj[node]){;
          int neighbour=v.first;
          int weight=  v.second;
          if(dist[node]+weight<dist[neighbour]){
              dist[neighbour]=dist[node]+weight;
              q.push(neighbour);
          }
      }
      }
      return dist;
  }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int weight=edges[i][2];
            adj[u].push_back({v,weight});
        }
        
        vector<int>ans=bfs(adj,V);
        for(int i=0;i<V;i++){
            if(ans[i]==1e9){
                ans[i]=-1;
            }
        }
        return ans;
    }
};


//using topological sort method
// TC : O(V + E) for topological sort + O(V + E) for relaxing edges = O(V + E)
// SC : O(V+E) for adjacency list + O(V) for visited + O(V) for answer vector = O(V + E)
//thismethod only works for DAG if there is a cycle then we will not get the correct
// answer as we are not checking for cycles in the graph.
class Solution {
  public:

    void topoSort(int node, vector<vector<pair<int,int>>>& adj,
                  vector<bool>& visited, stack<int>& st) {
        
        visited[node] = true;

        for(auto it : adj[node]) {
            int neighbour = it.first;

            if(!visited[neighbour]) {
                topoSort(neighbour, adj, visited, st);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        // build graph
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
        }

        // Topological sort
        vector<bool> visited(V, false);
        stack<int> st;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                topoSort(i, adj, visited, st);
            }
        }

        // Distance array
        vector<int> dist(V, 1e9);
        dist[0] = 0;

        // Relax edges in topo order
        while(!st.empty()) {
            int node = st.top();
            st.pop();

            if(dist[node] != 1e9) {

                for(auto it : adj[node]) {

                    int neighbour = it.first;
                    int weight = it.second;

                    if(dist[node] + weight < dist[neighbour]) {
                        dist[neighbour] = dist[node] + weight;
                    }
                }
            }
        }

        // Replace unreachable nodes
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};