
//TC : O(n)
//SC : O(1) (not considering the output vector) because we are using the Morris Traversal technique
//Morris Traversal is a way to traverse a binary tree without using recursion or a stack


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	
        vector<int>ans;
        TreeNode * curr= root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode * leftchild=curr->left;
                //find the rightmost node in the left subtree
                while(leftchild->right!=nullptr){
                    leftchild=leftchild->right;
                }
                //make a link to the root node
                leftchild->right=curr;
                TreeNode * temp=curr;
                curr=curr->left;

                //to break the link after visiting the left subtree
                temp->left=nullptr;
            }
        }
       return ans;
    }
};