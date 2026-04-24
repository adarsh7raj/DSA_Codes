//TC : O(V + E)
//SC : O(V + E) for the adjacency list and the visited array

class Solution {
public:

  void dfs(int parent,vector<vector<int>>&adj,vector<vector<int>>&ans, vector<bool>&visited,vector<int>&discovery,vector<int>&low,int node,int timer){
   
   visited[node]=true;
   discovery[node]=low[node]=timer;

   for(auto neigh:adj[node]){
    
    if(neigh==parent){
        continue;
    }
    else if(visited[neigh]){

        low[node]=min(low[node],discovery[neigh]);
    }
    else{
      
        dfs(node,adj,ans,visited,discovery,low,neigh,timer+1);
        if(discovery[node]<low[neigh]){
            ans.push_back({node,neigh});
        }
         low[node]=min(low[node],low[neigh]);
    }
   }

  }
  
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>discovery(n);
        vector<int>low(n);
        vector<bool>visited(n,false);
        vector<vector<int>>ans;

        vector<vector<int>>adj(n);

        for(int i=0;i<connections.size();i++){
         int u=connections[i][0];
         int v=connections[i][1];
         adj[u].push_back(v);
         adj[v].push_back(u);

        }
        for(int i=0;i<n;i++){
            if(!visited[i]){

   dfs(-1,adj,ans,visited,discovery,low,i,0);
            }
           

        }
        return ans;
    }
};