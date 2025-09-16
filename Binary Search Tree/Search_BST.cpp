
//TC: On average, searching in a BST is O(log n).But if unbalanced, in the worst case it degrades to O(n).
// SC: O(n)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val>val){
           return searchBST(root->left,val);
        }
        else if(root->val<val){
             return searchBST(root->right,val);
        }
     return root;
   
    }
};