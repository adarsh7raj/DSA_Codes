
//TC: O(n*m)
class Solution {
public:


void dfs(vector<vector<char>>& grid, int i, int j,vector<vector<int>>&visited) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j]=='X'|| visited[i][j]) {
            return;
        }
        visited[i][j]=1;
        grid[i][j] = 'S'; 

        dfs(grid, i + 1, j,visited);
        dfs(grid, i - 1, j,visited);
        dfs(grid, i, j + 1,visited);
        dfs(grid, i, j - 1,visited);
        
    }
    void solve(vector<vector<char>>& board) {
       int m=board.size();
       int n=board[0].size();
       vector<vector<int>>visited(m,vector(n,0));
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0|| j==0 || i==m-1 || j==n-1)
            if(board[i][j]=='O'){
                dfs(board,i,j,visited);
            }
        }
     }   
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='O'){
                board[i][j]='X';
            }
            else if(board[i][j]=='S'){
                board[i][j]='O';
            }
        }
     }
    }
};