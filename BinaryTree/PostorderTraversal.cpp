

// TC : O(n)
// SC : O(n) (not considering the output vector) because we are using recursion
class Solution {
public:
 void PostorderTreeTraversal(TreeNode* root,vector<int> & ans){
    if(root==nullptr){
        return;
    }
    PostorderTreeTraversal(root->left,ans);
    PostorderTreeTraversal(root->right,ans);
    ans.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        PostorderTreeTraversal(root,ans);
        return ans;
    }
};