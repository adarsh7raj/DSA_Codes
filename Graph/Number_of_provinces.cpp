

// TC : O(n^2) SC : O(n*n) for visited array
class Solution {
public:
 void dfs(vector<vector<int>> &adj,int node,vector<int>& visited,vector<int>&ans){
       
       visited[node]=1;
       ans.push_back(node);
       for(auto it:adj[node]){
           if(!visited[it]){
               dfs(adj,it,visited,ans);
           }
       }
       
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n+1);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && isConnected[i][j]==1){
                adj[i+1].push_back(j+1);
            }
        }
       }
        int count=0;
        vector<int>visited(n+1,0);
        for(int i=1;i<=n;i++){
       
            if(!visited[i]){
                     vector<int>temp;
                     dfs(adj,i,visited,temp);
                     count++;
            }
        }
        return count;
    }
};

// TC :O(n*n) SC : O(n) without using the adjency matrix

class Solution {
public:

    void dfs(vector<vector<int>>& isConnected,
             vector<int>& visited,
             int node) {

        visited[node] = 1;

        for(int j = 0; j < isConnected.size(); j++) {
            if(isConnected[node][j] == 1 && !visited[j]) {
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<int> visited(n, 0);

        int count = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(isConnected, visited, i);
                count++;
            }
        }

        return count;
    }
};
