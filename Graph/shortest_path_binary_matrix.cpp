// as in this  problem the weight to move form one cell to another is 1 , we can use bfs or dijkstra's algorithm to solve this problem. bfs is more efficient than dijkstra's algorithm in this case as it has a time complexity of O(n*n) in worst case when all cells are 0, while dijkstra's algorithm has a time complexity of O(n*n*log(n*n)) in worst case when all cells are 0.
// brute force approach 
// TC: O(n*n) in worst case when all cells are 0
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      using T = pair<int, pair<int,int>>; 
       vector<vector<int>>directions = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
int n=grid.size();
queue<T> q;
if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
    return -1;
}

  auto isSafe = [&](int x, int y,vector<vector<bool>>&visited) {
            return x >= 0 && x < grid.size() && y >= 0 && y<grid[x].size() && grid[x][y] == 0 && !visited[x][y];
        };
q.push({1,{0,0}});
vector<vector<bool>> visited(n, vector<bool>(n, false));
visited[0][0]=true;
while(!q.empty()){

    int count=q.top().first;
    int i=q.top().second.first;
    int j=q.top().second.second;
    if(i==n-1 && j==n-1){
        return count;
    }
    
    q.pop();
    for(auto & dir:directions){
        int new_i = i + dir[0];
        int new_j = j + dir[1];
        if(isSafe(new_i,new_j,visited)){
            q.push({count+1,{new_i,new_j}});
            visited[new_i][new_j]=true;
        }
    }
}
return -1;

    }
};



//  different approach using dijkstra's algorithm
// TC : O(n*n*log(n*n)) in worst case when all cells are 0

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        using T = pair<int, pair<int,int>>; // {dist, {i,j}}

        vector<vector<int>> directions = {
            {1,0}, {0,1}, {-1,0}, {0,-1},
            {1,1}, {-1,-1}, {1,-1}, {-1,1}
        };

        priority_queue<T, vector<T>, greater<T>> pq;

        // distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 1;
        pq.push({1, {0,0}});

        while(!pq.empty()) {
            auto [d, p] = pq.top();
            auto [i, j] = p;
            pq.pop();

            // If reached destination
         
            for(auto &dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if(ni >= 0 && nj >= 0 && ni < n && nj < n &&
                   grid[ni][nj] == 0) {

                    if(d + 1 < dist[ni][nj]) {
                        dist[ni][nj] = d + 1;
                        grid[ni][nj]=1; // mark visited
                        pq.push({d + 1, {ni, nj}});
                    }
                }
            }
        }
       if(dist[n-1][n-1]!=INT_MAX){
        return dist[n-1][n-1];
       }
        return -1;
    }
};