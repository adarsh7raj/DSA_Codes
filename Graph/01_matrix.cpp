// brute force approach
//TC:O(m*n)^2

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> ans(m, vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    continue;
                }

                // BFS for each 1 (your approach)
                queue<pair<int,int>> q;
                vector<vector<int>> visited(m, vector<int>(n,0));

                q.push({i,j});
                visited[i][j] = 1;

                int count = 0;

                while(!q.empty()){
                    int size = q.size();

                    while(size--){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        if(mat[x][y] == 0){
                            ans[i][j] = count;
                            goto done;
                        }

                        for(auto &dir : directions){
                            int new_i = x + dir[0];
                            int new_j = y + dir[1];

                            if(new_i>=0 && new_i<m && new_j>=0 && new_j<n 
                               && !visited[new_i][new_j]){

                                visited[new_i][new_j] = 1;
                                q.push({new_i,new_j});
                            }
                        }
                    }
                    count++;
                }
                done:;
            }
        }

        return ans;
    }
};


//optimal solution :
//TC:O(m*n)


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> ans(m, vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }

            auto isSafe = [&](int x, int y) {
            return x >= 0 && x < mat.size() && y >= 0 && y<mat[x].size();
        };
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
               
                for(auto &dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    if(isSafe(new_i,new_j) && ans[new_i][new_j]==-1){
                        ans[new_i][new_j]=1+ans[i][j];
                        q.push({new_i,new_j});
                    }

                }
        }

              return ans;
    }
};
