
// brute force
// TC: O(n^2) where n is the number of nodes in the binary tree
// SC: O(h) for the recursion stack where h is the height of the binary tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) { // leaf node
            return 0;
        }
 
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        if(abs(leftHeight-rightHeight)>1){
            return false;
        }
       int left=isBalanced(root->left);
       int right=isBalanced(root->right);
       if(left==true && right==true){
        return true;
       }
         return false;
    }
};


// optimal solution 
// TC: O(n) where n is the number of nodes in the binary tree
// SC: O(n) for the recursion stack
class Solution {
public:
  int height(TreeNode* root,bool  & balanced) {
        if (root == nullptr) { // leaf node
            return 0;
        }
 
        int leftHeight = height(root->left,balanced);
        int rightHeight = height(root->right,balanced);
        if(abs(leftHeight-rightHeight)>1){
            balanced=false;
        }

        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        bool balanced=true;
       height(root,balanced);
      return balanced;
    }
};