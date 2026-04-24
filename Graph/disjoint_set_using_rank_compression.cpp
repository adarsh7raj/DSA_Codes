
// this is the brute force approach of disjoint set union

// TC : O(N) for find and O(N) for union
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



// TC : O(4*alpha) ~ O(1)
// SC : O(N)


// optimal approach of disjoint set union using parent  and path compression

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;  // 👈 changed from size to rank

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);  // initially rank = 0

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);  // path compression
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        //  Union by Rank logic
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } 
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } 
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;  // increase rank when equal
        }
    }
};

int main() {
    DSU dsu(6);
    dsu.Union(0, 1);
    dsu.Union(0, 2);

    if (dsu.find(0) == dsu.find(3)) {
        cout << "In same component" << endl;
    } else {
        cout << "Not in same component" << endl;
    }

    dsu.Union(0, 3);

    if (dsu.find(0) == dsu.find(3)) {
        cout << "In same component" << endl;
    } else {
        cout << "Not in same component" << endl;
    }
}

// TC : O(4*alpha) ~ O(1)
// SC : O(N)
// This is the optimal approach of disjoint set union using union by size and path compression.

#include <bits/stdc++.h>
using namespace std;
class DSU {
    vector<int> parent;
	vector<int> size;
public:
    DSU(int n) {
    	parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;
            
        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
	    int x_parent = find(x);
	    int y_parent = find(y);
	
	    if (x_parent == y_parent) 
	        return;
	
	    if(size[x_parent] > size[y_parent]) {
	        parent[y_parent] = x_parent;
	        size[x_parent]  += size[y_parent];
	    } else if(size[x_parent] < size[y_parent]) {
	        parent[x_parent] = y_parent;
	        size[y_parent]  += size[x_parent];
	    } else {
	        parent[x_parent] = y_parent;
	        size[y_parent]  += size[x_parent];
	    }
	}
};
int main() {
    DSU dsu(6);
    dsu.Union(0, 1);
    dsu.Union(0, 2);
    
    // if 0 and 3 are not on same Component yet
    if (dsu.find(0) == dsu.find(3)) {
        cout << "In same component" << endl;
    } else {
    	cout << "Not in same component" << endl;
    }
    
    //Now we will Union 0 and 3
    dsu.Union(0, 3);
    if (dsu.find(0) == dsu.find(3)) {
        cout << "In same component" << endl;
    } else {
    	cout << "Not in same component" << endl;
    }
}