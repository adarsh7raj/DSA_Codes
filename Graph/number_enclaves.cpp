// TC: O(n*m) SC: O(n*m)
// it is similar to surrounded region problem but here we have to count the number of 
//enclaves which are not connected to boundary and are 1. So we will do dfs for all the boundary 
//1's and mark them as -1 and then count the number of 1's left in the grid which will be our answer.
class Solution {
public:
void dfs(vector<vector<int>>& grid, int i, int j,vector<vector<int>>&visited) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j]==0|| visited[i][j]) {
            return;
        }
        visited[i][j]=1;
        grid[i][j] = -1; 

        dfs(grid, i + 1, j,visited);
        dfs(grid, i - 1, j,visited);
        dfs(grid, i, j + 1,visited);
        dfs(grid, i, j - 1,visited);
        
    }
    int numEnclaves(vector<vector<int>>& board) {
         int m=board.size();
       int n=board[0].size();
       int count=0;
       vector<vector<int>>visited(m,vector(n,0));
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0|| j==0 || i==m-1 || j==n-1)
            if(board[i][j]==1){
                dfs(board,i,j,visited);
            }
        }
     }   
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==1){
             count++;
            }
           
        }
     }
     return count;
    }
};