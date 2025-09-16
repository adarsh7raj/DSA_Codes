

// TC : O(v^m) where v is the number of vertices and m is the number of colors
// SC : O(v) for the color map and O(v^2) for the adjacency matrix
// This is a backtracking solution for the M-coloring problem using an adjacency matrix representation of the graph.
// The function checks if it's possible to color the graph with m colors such that no two adjacent vertices have the same color.
// The solution uses a recursive approach to try coloring each vertex with one of the m colors,

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isSafe(int node, map<int, int>& color, const vector<vector<bool>>& graph, int v, int col) {
        for (int k = 0; k < v; k++) {
            if (k != node && graph[node][k]==1 && color[k] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, map<int, int>& color, int m, int v, const vector<vector<bool>>& graph) {
        if (node == v) return true;

        for (int c = 1; c <= m; c++) {
            if (isSafe(node, color, graph, v, c)) {
                color[node] = c;

                if (solve(node + 1, color, m, v, graph))
                    return true;

                color[node] = 0; // backtrack
            }
        }

        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // Step 1: Build adjacency matrix
        vector<vector<bool>> graph(v, vector<bool>(v, false));
        for (auto &edge : edges) {
            int u = edge[0], w = edge[1];
            graph[u][w] = true;
            graph[w][u] = true;
        }

        // Step 2: Use map for color assignment
        map<int, int> color;

        return solve(0, color, m, v, graph);
    }
};
