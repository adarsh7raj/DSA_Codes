// TC : O(n)
// SC : O(n) (not considering the output vector) because we are using recursion
class Solution {
public:
void PreorderTreeTraversal(TreeNode* root, vector<int> & ans){
    if(root==nullptr){
        return ;
    }
    ans.push_back(root->val);
    PreorderTreeTraversal(root->left,ans);
    PreorderTreeTraversal(root->right,ans);
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
         PreorderTreeTraversal(root,ans);
         return ans;
    }
};