
//TC: O(n*m*26) SC: O(n*m)  
class Solution {
public:

vector<int> topoSort(int N, vector<vector<int>>& adj){

    vector<int> indegree(N,0);

    for(int u=0;u<N;u++)
        for(int v:adj[u])
            indegree[v]++;

    queue<int> q;

    for(int i=0;i<N;i++)
        if(indegree[i]==0)
            q.push(i);

    vector<int> order;

    while(!q.empty()){

        int u=q.front();
        q.pop();

        order.push_back(u);

        for(int v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);
        }
    }

    return order;
}

string findOrder(vector<string> &words){

    vector<vector<int>> adj(26);
    set<char> seen_chars;
    for (auto& w : words)
        for (char c : w)
            seen_chars.insert(c);

    for(int i=0;i<words.size()-1;i++){

        string w1=words[i];
        string w2=words[i+1];

        int n=w1.size(), m=w2.size();
        int j=0;

        while(j<n && j<m){

            if(w1[j]!=w2[j]){

                int u=w1[j]-'a';
                int v=w2[j]-'a';

                adj[u].push_back(v);
                break;
            }

            j++;
        }

        if(j==m && n>m)
            return "";
    }

    vector<int> result=topoSort(26,adj);

    if(result.size()<26)
        return "";

    string ans="";

   for (int x : result)
        if (seen_chars.count('a' + x))
            ans += ('a' + x);
    return ans;
}
};