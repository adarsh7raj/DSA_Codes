

// using bfs

class Solution {
public:

void bfs(vector<vector<int>>& adj,vector<bool> & visited,int i){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
    
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

}
    int removeStones(vector<vector<int>>& stones) {
        int  stones_count=0;
        int V=stones.size();
        vector<vector<int>>adj(V);
        vector<bool>visited(V);
        for(int i=0;i<V;i++){
            int first=stones[i][0];
            int second=stones[i][1];

            for(int j=i+1;j<V;j++){
                if(stones[j][0]==first || stones[j][1]==second){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int components=0;

        for(int i=0;i<V;i++){

            if(!visited[i]){
           bfs(adj,visited,i);
           components++;

            }
        }

        return V-components;
    }
};


// using dsu


