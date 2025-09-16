
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