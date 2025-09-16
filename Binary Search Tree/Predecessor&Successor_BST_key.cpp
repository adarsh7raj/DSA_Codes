

// brute force solution
// TC : O(n) where n is the number of nodes in the binary tree



class Solution {
  public:
  int predecessor=INT_MIN;
  int successor=INT_MAX;
   void InorderTreeVal(Node* root,int key){
     if(root==nullptr){
            return ;
        }
        if(root->data!=key){
            if(root->data>key){
                successor=min(successor,root->data);
            }
            else{
                predecessor=max(predecessor,root->data);
            }
        }
       InorderTreeVal(root->left,key);
       
       InorderTreeVal(root->right,key);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*>ans;
        
      InorderTreeVal(root,key);
      if(predecessor==INT_MIN){
          predecessor=-1;
      }
      if(successor==INT_MAX){
         successor=-1;
      }
      Node* pred=new Node(predecessor);
      Node* succ=new Node(successor);
      ans.push_back(pred);
      ans.push_back(succ);
       return ans;
        
    }
};



// optimal solution // TC : O(n) where n is the number of nodes in the binary tree
// SC: O(1) no extra space used

 pair<Node*, Node*> findPreSuc(Node* root, int key) {
        Node* curr = root;
        Node* predecessor = nullptr;
        Node* successor = nullptr;

        // Step 1: Find the key node
        while (curr && curr->data != key) {
            if (key < curr->data) {
                successor = curr;  // Potential successor
                curr = curr->left;
            } else {
                predecessor = curr;  // Potential predecessor
                curr = curr->right;
            }
        }

        // If key is not found
        if (!curr) {
            return {predecessor, successor};
        }

        // Step 2: Find the max value in the left subtree (predecessor)
        if (curr->left) {
            Node* temp = curr->left;
            while (temp->right) {
                temp = temp->right;
            }
            predecessor = temp;
        }

        // Step 3: Find the min value in the right subtree (successor)
        if (curr->right) {
            Node* temp = curr->right;
            while (temp->left) {
                temp = temp->left;
            }
            successor = temp;
        }

        return {predecessor, successor};
    }
