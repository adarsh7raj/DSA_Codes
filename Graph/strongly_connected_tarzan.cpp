


// User function template for C++
// Function to return a list of lists of integers denoting the members
// of strongly connected components in the given graph.
class Solution {
  public:
    // Function to return a list of lists of integers denoting the members
    // of strongly connected components in the given graph.
    
    void dfs(int node, vector<int> adj[], vector<int>& disc, vector<int>& low,
             stack<int>& st, vector<bool>& inStack, int& timer,
             vector<vector<int>>& result) {
        
        disc[node] = low[node] = timer++;
        st.push(node);
        inStack[node] = true;
        
        for (auto neigh : adj[node]) {
            
            if (disc[neigh] == -1) {
                dfs(neigh, adj, disc, low, st, inStack, timer, result);
                low[node] = min(low[node], low[neigh]);
            }
            else if (inStack[neigh]) {
                low[node] = min(low[node], disc[neigh]);
            }
        }
        
        // SCC found
        if (low[node] == disc[node]) {
            vector<int> scc;
            
            while (true) {
                int v = st.top();
                st.pop();
                inStack[v] = false;
                scc.push_back(v);
                
                if (v == node) break;
            }
            
            sort(scc.begin(), scc.end()); // sort individual SCC
            result.push_back(scc);
        }
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        // code here
             
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;
        vector<vector<int>> result;
        
        int timer = 0;
        
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfs(i, adj, disc, low, st, inStack, timer, result);
            }
        }
        
        // sort list of SCCs
        sort(result.begin(), result.end());
        
        return result;
    }
};