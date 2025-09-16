

int find(int x, vector<int>& parent) {
    if (parent[x] == x) {
        return parent[x] // Path compression
    }
 return find(parent[x], parent);
}

void union(int x,int y,vector<int>&parent){
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);
    if(x_parent != y_parent) {
        parent[y_parent] = x_parent; // Union operation
    }
}