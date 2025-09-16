

// brute force solution
// TC : O(n) where n is the number of nodes in the binary tree
// SC: O(n) where n is the number of nodes in the binary tree, due to storing ancestors in a map
// This solution is not optimal for finding the lowest common ancestor in a binary tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==nullptr){
        return nullptr;
       }
       if(root==p){
        return p;
       }
       if(root==q){
        return q;
       }
       TreeNode* leftN=lowestCommonAncestor(root->left,p,q);
       TreeNode* rightN=lowestCommonAncestor(root->right,p,q);
       if(leftN!=nullptr && rightN!=nullptr){
   return root;
       }
       if(leftN==nullptr){
        return rightN;
       }
       if(rightN==nullptr){
        return leftN;
       }
return nullptr;
    }
};


// Optimized solution using 


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 // TC : O(h) where h is the height of the binary tree
// SC: O(1) for the iterative approach, O(h) for the recursive approach
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==nullptr){
        return nullptr;
       }
       // our root will be the LCA if we have to seperate p and q in different subtrees
        if(root->val == p->val || root->val == q->val) {
            return root;
        }
        // If both p and q are smaller than root, then LCA lies in left subtree
        // If both p and q are greater than root, then LCA lies in right subtree
 if(root->val < p->val && root->val < q->val) {
            // Both p and q are in the right subtree
            return lowestCommonAncestor(root->right, p, q);
        }
        if(root->val > p->val && root->val > q->val) {
            // Both p and q are in the left subtree
            return lowestCommonAncestor(root->left, p, q);
        }
        // We have found the split point, i.e., the LCA
        return root;
  

    }
};


