

// using dfs :
// it is similar to detecting cycle in directed graph
// if we complete the dfs for each node we can find the nodes which are in cycle and the nodes which are not in cycle
// the nodes which are not in cycle are the safe nodes
// the nodes which are true in the inRecursion vector are the nodes which are in cycle and
// the nodes which are false in the inRecursion vector are the nodes which are not in cycle
class Solution {
public:
 bool isCycleDFS(vector<vector<int>> &adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        
        for(int &v : adj[u]) {
            //if not visited, then we check for cycle in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            else if(inRecursion[v] == true)
                return true;
        }
        // when we backtrack
        inRecursion[u] = false;
        return false;
        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int V=graph.size();
            vector<int>ans;
            vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i]){
             isCycleDFS(graph, i, visited, inRecursion);
 
        }
    }
    for(int i=0;i<V;i++){
        if(inRecursion[i]==false){
            ans.push_back(i);
        }
    }
    return ans;
    }
};


//using bfs :


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n);

        // build reverse graph and outdegree
        for(int i=0;i<n;i++){

            for(int v : graph[i]){
                reverseGraph[v].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        // push terminal nodes
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> safe;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(int parent : reverseGraph[node]){
                indegree[parent]--;

                if(indegree[parent]==0){
                    q.push(parent);
                }
            }
        }

        sort(safe.begin(), safe.end());

        return safe;
    }
};