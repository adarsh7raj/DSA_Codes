

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        int sum=0;
        vector<vector<int>>adj[V];
        vector<bool>isVisited(V,false);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0,0});
        
        while(!pq.empty()){
            int wt =pq.top().first;
            int u=pq.top().second;
        
            pq.pop();
         
            if(!isVisited[u]){
                   sum=sum+wt;
                   for(auto node :adj[u]){
                   pq.push({node[1],node[0]});
               
            }
            }
                isVisited[u]=true;
         
        }
        return sum;
    }
};