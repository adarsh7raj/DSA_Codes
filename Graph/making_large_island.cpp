

//brute force approach where we are counting the number of islands after each query by doing a DFS on the grid. This is inefficient because we are recalculating the number of islands from scratch after each query, leading to a high time complexity, especially for larger grids and more queries. an give TLE

class Solution {
public:
   int dfs(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // invalid case
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            return 0;
        }

        // mark visited
        grid[i][j] = 0;

        int size = 1; // current cell

        // explore 4 directions
        size += dfs(i+1, j, grid);
        size += dfs(i-1, j, grid);
        size += dfs(i, j+1, grid);
        size += dfs(i, j-1, grid);

        return size;
    }

     int maxAreaOfIsland(vector<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(i, j, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int max_islands=0;
      for(int i=0;i<n;i++ ){
        for(int j=0;j<n;j++){

            if(grid[i][j]==0){
                grid[i][j]=1;
              max_islands=max(maxAreaOfIsland(grid),max_islands);
              grid[i][j]=0;
            }
        }
      }

      if(max_islands==0){
        return n*n;
      }
      return max_islands;
    }
};

// optimal approach using union set

class Solution {
public:
vector<int> parent;
vector<int> size;
bool isValid(int nr,int nc,int n){

    if(nr<n && nr>=0 && nc<n && nc>=0 ){
        return true;
    }
    return false;
}

 int find(int x) {
        if (x == parent[x])
            return x;
            
        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
	    int x_parent = find(x);
	    int y_parent = find(y);
	
	    if (x_parent == y_parent) 
	        return;
	
	    if(size[x_parent] > size[y_parent]) {
	        parent[y_parent] = x_parent;
	        size[x_parent]  += size[y_parent];
	    } else if(size[x_parent] < size[y_parent]) {
	        parent[x_parent] = y_parent;
	        size[y_parent]  += size[x_parent];
	    } else {
	        parent[x_parent] = y_parent;
	        size[y_parent]  += size[x_parent];
	    }
	}



    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int max_islands=0;
         parent.resize(n*n);
        size.resize(n*n);
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        for (int i = 0; i < n*n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
       for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
           if(grid[i][j]==1){
         for(int idx=0;idx<4;idx++){
            int nr=i+dr[idx];
            int nc=j+dc[idx];
            int curr_node=i*n+j;
            int new_node=nr*n+nc;
            if(isValid(nr,nc,n) && grid[nr][nc]==1 ){
            if(find(curr_node)!=find(new_node)){
                Union(curr_node,new_node);
            }
            }
         }
           }
        }
       }
    
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          unordered_set<int>st;
            if( grid[i][j]==0){
               for(int idx=0;idx<4;idx++){
            int nr=i+dr[idx];
            int nc=j+dc[idx];
            int curr_node=i*n+j;
            int new_node=nr*n+nc;
            if(isValid(nr,nc,n) && grid[nr][nc]==1){
                int ultimate_parent=find(new_node);
                st.insert(ultimate_parent);
            }
            }

            int islands_size=1;
            for(auto it : st){
             islands_size+=size[it];
            }
            max_islands=max(max_islands,islands_size);
        }
       }
  
    }
     return max_islands==0? n*n : max_islands;
    }
};


// optimal solution using uniquely making nodes : 



class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0},{0, 1},{0, -1}};

    int DFS(vector<vector<int>>& grid, int i, int j, int& id) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return 0;
        
        grid[i][j] = id;
        int count  = 1;
        
        for(vector<int>& dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];
            
            count += DFS(grid, x, y, id);
        }
        
        return count;
    }
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        unordered_map<int, int> mp;
        int island_id = 2;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    int size = DFS(grid, i, j, island_id);
                    maxArea = max(maxArea, size);
                    mp[island_id] = size;
                    island_id++;
                }
            }
        }
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> st;
                    for(vector<int>& dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0)
                            st.insert(grid[x][y]);
                    }
                    
                    int sum = 1; //converting current 0 to 1
                    for(const int &s : st) {
                        sum += mp[s];
                    }
                    maxArea = max(maxArea, sum);
                }
            }
        }
        
        return maxArea;
    }
};
