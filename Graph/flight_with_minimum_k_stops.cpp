
// wecan not use priority queue in this problem as we need to consider the number of stops as 
//well, if we use priority queue then we will always get the minimum cost flight first but it 
//may not be the case that it has the minimum number of stops, so we need to use a queue to 
//store the flights and process them level by level, where each level represents the number 
//of stops, and we will only consider the flights that have the same number of stops at each 
//level, and we will update the distance array accordingly, and at the end we will return the 
//distance to the destination if it is not infinity, otherwise we will return -1.

// we can use priority queue if we sort the flights based on the stops i.e {stops,{cost,node}}
//Approach-1 (BFS)
//T.C : O(V+E) - BFS traversal of Graph
//S.C : O(V+E)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(vector<int> &vec : flights) {
            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];
            
            adj[u].push_back({v, cost});
        }
        
        queue<pair<int, int>> que;
        que.push({src, 0});
        distance[src] = 0;
        
        int level = 0;
        
        while(!que.empty() && level <= k) {
            int N = que.size();
            
            while(N--) {
                int u = que.front().first;
                int d = que.front().second;
                que.pop();
                
                for(pair<int, int> &P : adj[u]) {
                    
                    int v    = P.first;
                    int cost = P.second;
                    
                    if(distance[v] > d + cost) {
                        distance[v] = d + cost;
                        que.push({v, d+cost});
                    }
                    
                }
                
            }
            level++;
        }
        
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};


// another approach : 



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // Build adjacency list
        vector<pair<int,int>> adj[n];
        for(auto &f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        // queue: {node, cost, stops}
        queue<tuple<int,int,int>> q;
        q.push({src, 0, 0});

        // distance array
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()) {
            auto [node, cost, stops] = q.front();
            q.pop();

            // if stops exceeded → skip
            if(stops > k) continue;

            for(auto &nbr : adj[node]) {
                int next = nbr.first;
                int wt   = nbr.second;

                int newCost = cost + wt;

                if(newCost < dist[next]) {
                    dist[next] = newCost;
                    q.push({next, newCost, stops + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};



