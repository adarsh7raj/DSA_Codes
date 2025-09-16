// TC : O(V + E)
// SC : O(V)

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n = 6; // number of nodes
    vector<vector<int>> adj(n);
    // Example: undirected edges (0-1, 0-2, 1-3, 1-4, 2-4, 3-5, 4-5)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};

    vector<bool> visited(n, false);
    cout << "DFS traversal starting from node 0: ";
    dfs(0, adj, visited);
    cout << endl;
    return 0;
}
