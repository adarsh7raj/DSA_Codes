
// DFS
class Solution {
public:
bool dfs(vector<vector<int>> & graph, vector<int> & color , int node, int currcolor){
    color[node]=currcolor;
    for(auto u:graph[node]){
        if(color[u]==color[node]){
            return false;
        }
        if(color[u]==-1){
           int nextcolor=1-currcolor;
             if(dfs(graph,color,u,nextcolor)==false){
            return false;
        }
        }
      
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if( dfs(graph,color,i,1)==false){
  return false;
                }
               
            }
        }
        return true;
    }
};

// BFS


class Solution {
public:
bool bfs(vector<vector<int>> & graph, vector<int> & color , int node, int currcolor){
    queue<int>q;
    q.push(node);
    color[node]=currcolor;
    while(!q.empty()){
        int v=q.front();
        q.pop();
for(auto u:graph[v]){
        if(color[u]==color[v]){
            return false;
        }
      else  if(color[u]==-1){
           color[u]=1-color[v];
          q.push(u);
        }
      
    }
    
    
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if( bfs(graph,color,i,1)==false){
  return false;
                }
               
            }
        }
        return true;
    }
};