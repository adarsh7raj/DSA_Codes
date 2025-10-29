
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



//we can also do this : 


class Solution {
public:
    void dfs(vector<vector<int>>& maze,
             int i, int j,
             int n,
             string& path,
             vector<string>& result,
             vector<vector<bool>>& visited) {
        
        // ✅ Boundary and validity checks on top
        if (i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0 || visited[i][j])
            return;

        // ✅ If we reached the destination, store the path
        if (i == n - 1 && j == n - 1) {
            result.push_back(path);
            return;
        }

        // Mark current cell visited
        visited[i][j] = true;

        // Directions and corresponding move chars
        string moves = "DLRU";
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};

        // Explore all 4 directions
        for (int k = 0; k < 4; k++) {
            path.push_back(moves[k]);
            dfs(maze, i + dx[k], j + dy[k], n, path, result, visited);
            path.pop_back(); // backtrack
        }

        // Unmark for backtracking
        visited[i][j] = false;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> result;
        int n = maze.size();
        if (n == 0) return result;

        // Edge case: start or end blocked
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return result;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string path = "";
        dfs(maze, 0, 0, n, path, result, visited);
        return result;
    }
};



// another approach :
// without using visited array

class Solution {
public:
    void dfs(vector<vector<int>>& maze,
             int i, int j,
             int n,
             string& path,
             vector<string>& result) {

        // ✅ Boundary & validity check on top
        if (i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0)
            return;

        // ✅ If destination reached
        if (i == n - 1 && j == n - 1) {
            result.push_back(path);
            return;
        }

        // Mark current cell as visited (temporarily block it)
        maze[i][j] = 0;

        // Directions: Down, Left, Right, Up
        string moves = "DLRU";
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            path.push_back(moves[k]);
            dfs(maze, i + dx[k], j + dy[k], n, path, result);
            path.pop_back(); // backtrack
        }

        // Unmark cell (restore its original value)
        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> result;
        int n = maze.size();
        if (n == 0) return result;

        // Edge case: start or end blocked
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return result;

        string path = "";
        dfs(maze, 0, 0, n, path, result);
        return result;
    }
};

