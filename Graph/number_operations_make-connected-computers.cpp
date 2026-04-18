
//just find the number of components

class Solution {
public:

void bfs(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

    
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {

        vector<vector<int>>adj(n);
    for (auto& edge : connections) {
        int u = edge[0];
        int v = edge[1];
       
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(n,false);

     if(n-1>connections.size()){

     return -1;
         }

         int components=0;
         for(int i=0;i<n;i++){
            if(!visited[i]){
         bfs(i, adj, visited);
         components++;
            }
         }
        return components-1;

    }
};


//optimal using dsu:


class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1)
            return -1;
        
        parent.resize(n);
        rank.resize(n, 0);
        
        for(int i = 0; i<n; i++)
            parent[i] = i;
        
        int components = n;
        for(auto &vec : connections) {
            if(find(vec[0]) != find(vec[1])) {
                components--;
                Union(vec[0], vec[1]);
            }
        }
        return components-1;
    }
}; 