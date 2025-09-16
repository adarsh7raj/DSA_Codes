

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
void PreorderTraversal(TreeNode * root,int  level, vector<int>& ans){
    if(root==nullptr){
        return ;
    }
    if(level>ans.size()){
        ans.push_back(root->val);
    }
    PreorderTraversal(root->left,level+1,ans);
    PreorderTraversal(root->right,level+1,ans);

}
    vector<int> leftSideView(TreeNode* root) {
        vector<int>ans;
        PreorderTraversal(root,1,ans);
        return ans;
    }
};