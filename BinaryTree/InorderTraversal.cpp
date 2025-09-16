

/// TC : O(n)
/// SC : O(n) (not considering the output vector) because we are using recursion
class Solution {
public:
   void Inorder(TreeNode* root,vector<int>  & ans){
     if(root==nullptr){
            return ;
        }
       Inorder(root->left,ans);
         ans.push_back(root->val);
         Inorder(root->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
      Inorder(root,ans);
      return ans;
}
};