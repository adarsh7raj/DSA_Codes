// Why BFS Guarantees Shortest Path
// When BFS visits a node for the first time, it has taken the fewest possible edges to get there. Here's why:

// Layer 0 → source node (distance 0)
// Layer 1 → all nodes 1 edge away
// Layer 2 → all nodes 2 edges away
// Layer N → all nodes N edges away

// Since BFS processes nodes in order of distance, the moment you reach a node, that distance is 
// already minimal. A longer path to the same node would only arrive later in the queue — but 
// the node is already marked visited, so it's never re-processed.

// Why Not DFS?
// DFS would go deep first — it might reach node 3 via a path of length 5 before finding the path 
// of length 3. BFS can't make this mistake because it physically cannot process a distance-3 node 
// before finishing all distance-2 nodes.

//TC : O(V + E)
//SC : O(V+E) for adjacency list + O(V) for visited + O(V) for answer vector = O(V + E)

class Solution {
  public:

  vector<int> bfs(int start,int V, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int,int>> q;
    vector<int>ans(V,-1);
    q.push({start,0});
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front().first;
        int dist=  q.front().second;
        ans[node]=dist;
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push({neighbor,dist+1});
                visited[neighbor] = true;
            
                }
                }
    
                }
    return ans;
  
}
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>>adj(V);
       
         vector<bool> visited(V, false);
         for(int i=0;i<edges.size();i++){
           int u= edges[i][0];
           int v=edges[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);
         }
      return  bfs(src,V,adj,visited);
        
        
        
    }
                
};


// more intitutive approach

// TC : O(V + E)
// SC : O(V+E) for adjacency list + O(V) for visited + O(V) for answer vector = O(V + E)

class Solution {
  public:

  vector<int> bfs(int start,int V, const vector<vector<int>>& adj) {
    queue<int> q;
    vector<int>ans(V,1e9);
    q.push(start);
    ans[start]=0;
    while (!q.empty()) {
        int node = q.front();
     
    
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (ans[node]+1<ans[neighbor]) {
                ans[neighbor]=ans[node]+1;
                q.push(neighbor);
                
            
                }
                }
    
                }
                
    return ans;
  
}
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>>adj(V);
       
         vector<bool> visited(V, false);
         for(int i=0;i<edges.size();i++){
           int u= edges[i][0];
           int v=edges[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);
         }
      vector<int>result=  bfs(src,V,adj);
      for(int i=0;i<V;i++){
          if(result[i]==1e9){
              result[i]=-1;
              
              
          }
      }
        
        return result;
        
    }
                
};
