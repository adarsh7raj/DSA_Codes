

// brute force approach
// TC : O(n) where n is the number of nodes in the binary tree



class Solution {

  public:
  int  predecessor=INT_MIN;
   void InorderTreeVal(Node* root,int key){
     if(root==nullptr){
            return ;
        }
        
            if(root->data<=key){
           predecessor=max(predecessor,root->data);
            }
           
        
       InorderTreeVal(root->left,key);
       
       InorderTreeVal(root->right,key);
    }
    int floor(Node* root, int x) {
        // Code here
        if(predecessor==INT_MIN){
            predecessor=-1;
        }
        InorderTreeVal(root,x);
        return predecessor;
        
    }
};


// optimal solution
// TC : O(h) where h is the height of the binary tree
// SC: O(1) no extra space used


int ceil(Node * root, int x) {
    int ceil = -1; // Initialize ceil to -1 (not found)
    while (root != nullptr) {
        if (root->data == x) {
            return root->data; // Found exact match
        } else if (root->data < x) {
            root = root->right; // Move to right subtree
        } else {
            ceil = root->data; // Update ceil
            root = root->left; // Move to left subtree
        }
    }
    return ceil; // Return the found ceil value or -1 if not found
}