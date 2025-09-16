// TC : O(V + E)
// SC : O(V)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int, int>> q;  // {current_node, parent_node}
    visited[start] = true;
    q.push({start, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                // Visited neighbor that's not the parent: cycle detected!
                return true;
            }
        }
    }
    return false;
}

bool containsCycle(int V, const vector<vector<int>>& edges) {
    // Build adjacency list
    vector<vector<int>> adj(V);
    for (const auto& e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(V, false);

    // Check all components (disconnected graph)
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (bfs(i, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,2},{3,4}};
    if (containsCycle(V, edges)) {
        cout << "Graph contains a cycle\n";
    } else {
        cout << "No cycle in the graph\n";
    }
    return 0;
}


// using DFS to detect cycle in an undirected graph
// TC : O(V + E)
// SC : O(V)

#include <vector>
using namespace std;

// Utility function for DFS and cycle detection
bool dfs(int node, int parent, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true; // Cycle found
        } else if (neighbor != parent) {
            return true; // Found a visited node that is not the parent
        }
    }
    return false;
}

// Main function to check for cycle
bool containsCycle(int V, const vector<vector<int>>& edges) {
    // Build adjacency list
    vector<vector<int>> adj(V);
    for(const auto& e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(V, false);

    for(int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}
