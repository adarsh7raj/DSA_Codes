


// using binary search to find the minimum time when we can reach from source to destination

//TC : O(n*n*log(n*n)) where n is the dimension of the grid or O(n*n*log(n)) where n is the maximum value in the grid
//SC : O(n*n) for the visited array
class Solution {
public:
bool isPossible(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&visited , int n , int mid){

  if(i>=n || j>=n || i<0 || j<0 || grid[i][j]>mid || visited[i][j]==true){
    return false;
  }
  visited[i][j]=true;
  if(i==n-1 && j==n-1){
    return true;
  }
  
  if(isPossible(i+1,j,grid,visited,n,mid)|| isPossible(i-1,j,grid,visited,n,mid)|| isPossible(i,j+1,grid,visited,n,mid)|| isPossible(i,j-1,grid,visited,n,mid)){

    return true;
  }

return false;
}
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
       int l=grid[0][0];
       int r=n*n-1;
       int result=0;
      
      while(l<=r){
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        int mid=(r-l)/2+l;

         if(isPossible(0,0,grid,visited,n,mid)){
            result=mid;
            r=mid-1;
         }
         else{
            l=mid+1;
         }
      }
      return result;
    }
};


// optimal approach using dijkstra's algorithm


#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // Min-heap: stores {elevation, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        int max_path = 0;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            // Update the maximum height seen so far on this path
            max_path = max(max_path, d);
            
            // If we reached the destination
            if (r == n - 1 && c == n - 1) return max_path;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({grid[nr][nc], {nr, nc}});
                }
            }
        }
        return max_path;
    }
};