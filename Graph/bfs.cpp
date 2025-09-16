
// TC : O(V + E)
// SC : O(V)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
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
    cout << "BFS traversal starting from node 0: ";
    bfs(0, adj, visited);
    cout << endl;
    return 0;
}
