

class Solution {
public:

vector<int> parent;
vector<int> rank;

int find (int x) {
    if (x == parent[x]) 
        return x;

    return parent[x] = find(parent[x]);
}


void Union (int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent) 
        return;

    if(rank[x_parent] > rank[y_parent]) {
        parent[y_parent] = x_parent;
    } else if(rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
    } else {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
         parent.resize(n);
    rank.resize(n, 0);
    for(int i = 0; i < n; i++) parent[i] = i;
        unordered_map<string,int>mp;

        for(int i=0;i<n;i++){

            for(int j=1;j<accounts[i].size();j++){

             string email=accounts[i][j];

             if(!mp.count(email)){
                 mp[email]=i;

             }
             else{
                Union(i,mp[email]);
             }
            }
        }
        vector<vector<string>>email_node(n);

        for(auto it:mp){
            string email=it.first;
            int node=find(it.second);

            email_node[node].push_back(email);
        }
   vector<vector<string>>ans;

   for(int i=0;i<n;i++){
   vector<string>temp;
   if(email_node[i].size()==0){
    continue;
   }
   sort(email_node[i].begin(),email_node[i].end());
   temp.push_back(accounts[i][0]);
    for(auto it:email_node[i]){
      temp.push_back(it);
    }
    ans.push_back(temp);
   }
   return ans;
    }
};