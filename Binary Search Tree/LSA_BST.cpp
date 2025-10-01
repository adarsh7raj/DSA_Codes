

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


// Optimized solution using concept of BST
// ⏱ Complexity

// Time Complexity: O(h) where h = height of the BST.

// Balanced BST → O(log n).

// Skewed BST → O(n).

// Space Complexity:

// Recursive: O(h) (function call stack).

// Iterative: O(1).


// 🌟 Intuition

// We are trying to find the lowest common ancestor (LCA) of two nodes p and q in a BST.
// By definition:

// The LCA of two nodes is the lowest node in the tree that has both p and q as descendants.

// Now, since this is a BST, we can use its special property:
// 👉 For any node root:

// All nodes in the left subtree have values smaller than root->val.

// All nodes in the right subtree have values greater than root->val.

// So instead of searching blindly:

// If both p and q are smaller than root->val, the LCA must lie in the left subtree.

// If both p and q are greater than root->val, the LCA must lie in the right subtree.

// Otherwise (if one is smaller and the other is greater, or one equals the root), the current node is the split point → LCA.

// This works because the moment p and q “separate” across a node, that node is their first common ancestor.

// 📝 Algorithm

// Start from the root of the BST.

// If root is nullptr, return nullptr.

// Compare root->val with p->val and q->val:

// If root->val < p->val and root->val < q->val:
// → Both nodes lie in the right subtree, so recurse on root->right.

// If root->val > p->val and root->val > q->val:
// → Both nodes lie in the left subtree, so recurse on root->left.

// Otherwise:
// → The current node is the split point → return root as LCA.
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


