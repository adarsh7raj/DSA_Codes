
// this brute force 
// TC: O(q * n * m) where q is the number of queries and n, m are the dimensions of the grid
// SC: O(n * m) for the grid and the recursive stack space in the worst case
void dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
            return;
        }

        grid[i][j] = 2; // mark as visited

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        
    }
int numIslands(vector<vector<int>> grid) {
       int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    count++; // one full island is explored
                }
            }
        }
        return count;
    }

vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& A, int q)
{
    // Write your code here.
      vector<int>ans;
    
        vector<vector<int>>mat(n,vector<int>(m,0));
        
        for(int idx=0;idx<q;idx++){
            int i=A[idx][0];
            int j=A[idx][1];
            mat[i][j]=1;
            int number_islands=numIslands(mat);
            ans.push_back(number_islands);
        }
       
  return ans;
}


//optimal approach using union find

vector<int> parent, rankArr;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py) return;

    if (rankArr[px] > rankArr[py]) {
    parent[py] = px;
} else if (rankArr[px] < rankArr[py]) {
    parent[px] = py;
} else {
    parent[px] = py;
    rankArr[py]++;
}
}

bool isValid(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& A, int q) {
    vector<int> ans;
    vector<vector<int>> mat(n, vector<int>(m, 0));

    parent.resize(n * m);
    rankArr.resize(n * m, 0);

    for (int i = 0; i < n * m; i++) parent[i] = i;

    int count = 0;

    for (int idx = 0; idx < q; idx++) {
        int i = A[idx][0];
        int j = A[idx][1];

        if (mat[i][j] == 1) {
            
            continue;
        }

        mat[i][j] = 1;
        count++;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];

            if (isValid(ni, nj, n, m) && mat[ni][nj] == 1) {
                int node = i * m + j;
                int adjNode = ni * m + nj;

                if (find(node) != find(adjNode)) {
                    count--;
                    Union(node, adjNode);
                }
            }
        }

        ans.push_back(count);
    }

    return ans;
}