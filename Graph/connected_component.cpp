
// brute force this will give TLE
// TC : O(V + E) for DFS traversal of each component
class Solution {
  public:
   void dfs(vector<int>adj[],int node,vector<int>& visited,vector<int>&ans){
       
       visited[node]=1;
       ans.push_back(node);
       for(auto it:adj[node]){
           if(!visited[it]){
               dfs(adj,it,visited,ans);
           }
       }// do not return cause this will give TLE fofr large test cases
       
   }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<vector<int>>ans;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
       
            if(!visited[i]){
                     vector<int>temp;
                     dfs(adj,i,visited,temp);
                  ans.push_back(temp);
            }
        }
        return ans;
       
    }
};
