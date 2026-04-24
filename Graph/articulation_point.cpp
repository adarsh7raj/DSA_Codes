

// User function Template for C++

class Solution {
  public:
  
   void dfs(int parent,vector<int>adj[],vector<int>&ans, vector<bool>&visited,vector<int>&discovery,vector<int>&low,int node,int timer){
   
   visited[node]=true;
   discovery[node]=low[node]=timer;
   int count=0;
   for(auto neigh:adj[node]){
    
    if(neigh==parent){
        continue;
    }
    else if(visited[neigh]){

        low[node]=min(low[node],discovery[neigh]);
    }
    else{
      
        dfs(node,adj,ans,visited,discovery,low,neigh,timer+1);
        count++;
        if(discovery[node]<=low[neigh] && parent!=-1){
            ans[node]=1;
        }
         low[node]=min(low[node],low[neigh]);
          
    }
   
   }
   if(parent==-1 && count>1){
        ans[node]=1;
    }

  }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
         vector<int>discovery(V);
        vector<int>low(V);
        vector<bool>visited(V,false);
        vector<int>ans(V,0);
        vector<int>result;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){

   dfs(-1,adj,ans,visited,discovery,low,i,0);
            }
           

        }
       for(int i=0;i<V;i++){
           
           if(ans[i]){
               result.push_back(i);
           }
       }
        if(result.size()==0){
            result.push_back(-1);
        }
        return result;
    }
};