
// TC: O(4^(n^2)) where n is the size of the maze
// SC: O(n^2) for the visited matrix and O(n^2) for the recursion stack

class Solution {
  public:
    bool isValid(int x, int y, int n, vector<vector<int>> &maze, vector<vector<bool>> &visited) {
        return x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && !visited[x][y];
    }

    void ratSolve(vector<vector<int>> &maze, int i, int j, int n, string &sol, vector<string> &ans, vector<vector<bool>> &visited) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(sol);
            return;
        }

        visited[i][j] = true;
        string moves = "DLRU";
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (isValid(ni, nj, n, maze, visited)) {
                sol.push_back(moves[k]);
                ratSolve(maze, ni, nj, n, sol, ans, visited);
                sol.pop_back(); // backtrack
            }
        }

        visited[i][j] = false;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze) {
        vector<string> ans;
        int n = maze.size();
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string sol = "";
        ratSolve(maze, 0, 0, n, sol, ans, visited);
        return ans;
    }
};
