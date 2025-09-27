

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

//Iterative approach TC: O(n) SC: O(n)


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;

        // Instead of while(true), use condition
        while (node != nullptr || !st.empty()) {
            // Push all left children
            while (node != nullptr) {
                st.push(node);
                node = node->left;
            }

            // Process top of stack
            node = st.top();
            st.pop();

            ans.push_back(node->val);

            // Move to right subtree
            node = node->right;
        }

        return ans;
    }
};


// another iterative approach TC: O(n) SC: O(n)

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
    vector<int> inorderTraversal(TreeNode* root) {
    	//your code goes here
        vector<int>ans;
        TreeNode* node=root;
        stack<TreeNode*>st;
       
      while(1){
        if(node!=nullptr){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()){
                break;
            }
            node=st.top();
            st.pop();
            ans.push_back(node->val);
            node=node->right;
        }
      }
       return ans;
    }
};