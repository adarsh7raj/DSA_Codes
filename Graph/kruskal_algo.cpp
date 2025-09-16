class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return find(parent[x]); // Path compression
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent != y_parent) {
            parent[y_parent] = x_parent;
        }
    }

    int Kruskal(int V, vector<vector<int>> &vec) {
        parent.clear();
        for (int i = 0; i < V; i++) {
            parent.push_back(i);
        }

        int sum = 0;
        for (auto &temp : vec) {
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v) {
                Union(u, v);
                sum += wt;
            }
        }
        return sum;
    }

    int spanningTree(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2]; // sort by weight
        });

        return Kruskal(V, edges);
    }
};
