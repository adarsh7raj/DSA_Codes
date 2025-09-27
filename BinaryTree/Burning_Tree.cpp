
// question :
// Given a binary tree and a target node, determine the minimum time required to burn the entire
// tree if the target node is set on fire. In one second, the fire spreads from a node to its
// left child, right child, and parent.
// Note: The tree contains unique values.


// Intuition

// Fire spreads from a target node to its left child, right child, and parent in one unit of time.

// This is basically like a graph problem where each node is connected to its children and parent.

// We need to find the maximum distance from the target node to any other node, because the farthest node will decide how long the burning takes.

// So we:

// Build a map of parent pointers for each node (since binary tree nodes don’t store parents by default).

// Use BFS (level-order traversal) starting from the target node, where each level represents 1 second of burning.

// Track visited nodes to avoid cycles.

// The last level processed gives the time to burn the entire tree.

// 📑 Algorithm

// Find Parent Mapping

// Do a DFS (inorder) traversal and store parent[child] = parentNode.

// This allows us to move upward in BFS.

// Find Target Node

// Recursively search the tree to get the node where fire starts.

// BFS Burning Simulation

// Start BFS from the target node.

// For each node, push its left child, right child, and parent (if not visited).

// Each BFS level = 1 unit of time.

// Return Answer

// The last level processed gives total time.

// Since at the end BFS runs one extra level, return time_fire - 1.



class Solution {
  public:
  Node* find_target(Node* root, int target){
      if(root==nullptr){
          return nullptr;
      }
      if(root->data==target){
          return root;
      }
     Node*left= find_target(root->left,target);
     Node*right= find_target(root->right,target);
     if(left!=nullptr && left->data==target){
         return left;
     }
     if(right!=nullptr && right->data==target){
         return right;
     }
     return nullptr;
  }
  void inorder(Node*root,map<Node*,Node*>&mp){
      if(root==nullptr){
          return ;
      }
      if(root->left!=nullptr){
          mp[root->left]=root;
          inorder(root->left,mp);
      }
        if(root->right!=nullptr){
          mp[root->right]=root;
          inorder(root->right,mp);
      }
      
  }
    int minTime(Node* root, int target) {
        // code here
        map<Node*,Node*>parent;
        inorder(root,parent);
      Node* Target= find_target(root,target);
      
      queue<Node*>q;
      int time_fire=0;
      q.push(Target);
      unordered_set<int>visited;
      visited.insert(Target->data);
      while(!q.empty()){
          int n=q.size();
          for(int i=0;i<n;i++){
             Node*curr=q.front(); 
             q.pop();
             if(curr->left!=nullptr && !visited.count(curr->left->data)){
                 q.push(curr->left);
                 visited.insert(curr->left->data);
                 
             }
                 if(curr->right!=nullptr && !visited.count(curr->right->data)){
                 q.push(curr->right);
                 visited.insert(curr->right->data);
                 
             }
             if(parent.count(curr) && !visited.count(parent[curr]->data)){
                 q.push(parent[curr]);
                 visited.insert(parent[curr]->data);
             }
          }
          time_fire++;
      }
        return time_fire-1;
    }
};