
// brute force solution
//TC : O(n)  SC : O(n)


 
class Solution {
public:
void InorderTraversal(TreeNode * root,vector<TreeNode*>& ans){
    if(root==nullptr){
        return ;
    }
    ans.push_back(root);
    InorderTraversal(root->left,ans);
    InorderTraversal(root->right,ans);
}
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return ;
        }
        vector<TreeNode*>ans;
        InorderTraversal(root,ans);
        int i=0;
       while(i<ans.size()-1){
        TreeNode* temp=ans[i];
       
              temp->right=ans[i+1];
              temp->left=nullptr;
        
        i++;
       
       }
    }
};

// optimal solution
// TC : O(n) SC : O(1) (not considering the output vector)

class Solution {
    public:
    void flatten(TreeNode* root){
        TreeNode * curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                curr=curr->right;
            }
            else{
                TreeNode* leftchild=curr->left;
                while(leftchild->right!=nullptr){
                    leftchild=leftchild->right;

                }
                leftchild->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;
                curr=curr->right;
            }
        }
    }
}