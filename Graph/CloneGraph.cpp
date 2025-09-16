// using DFS to clone the graph

class Solution {
public:
    map<Node*,Node*>visited;
    void DFS(Node* node, Node* clone_node) {
        visited[node] = clone_node;
        
        for(Node* x : node->neighbors) {
            if(!visited.count(x)) {
                Node* clone = new Node(x->val);
                clone_node->neighbors.push_back(clone);
                DFS(x, clone);
            } else {
                clone_node->neighbors.push_back(visited[x]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        //cloned the given node
        Node* clone_node = new Node(node->val);
        
        //Now, clone its neighbours and recursively their neighbours
        /*
            But if a node reappears, then we need to access that cloned node
            So, store them in a vector to access
        */
        
       //Using contraints given
        //We could use map also if constraints are not clear (i.e. unordered_map<Node*, Node*> visited;)
        visited[node] = clone_node;
        

        DFS(node, clone_node);
 
        
        
        return clone_node;
    }
};


// BFS 

 
    void BFS(queue<Node*> &que) {
        
        while(!que.empty()) {
            
            Node* node = que.front();
            Node* clone_node = mp[node];
            que.pop();
            
            for(Node* n : node->neighbors) {
            
                if(mp.find(n) == mp.end()) {

                    Node* clone = new Node(n->val);
                    mp[n] = clone;
                    clone_node->neighbors.push_back(clone);

                    //DFS(n, clone);
                    que.push(n);

                } else {

                    clone_node->neighbors.push_back(mp[n]);

                }
            
            }
            
        }
        
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        mp.clear();
        
        //cloned the given node
        Node* clone_node = new Node(node->val);
        
        //Now, cloe its neighbours and recursively their newighbours
        /*
                But if a node reappears, then we need to access that cloned node
                So, store them in a map <Node*, Node*>
        */
        
        mp[node] = clone_node;
        
        queue<Node*> que;
        que.push(node);
        BFS(que);
        
        return clone_node;
    }
};