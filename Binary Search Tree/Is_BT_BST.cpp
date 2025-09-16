class Solution {
public:

    /*
     * Helper function to validate if a binary tree is a valid Binary Search Tree (BST).
     * Each node must lie within a range: > minvalue and < maxvalue
     * Traverses the tree in DFS fashion and checks BST property at each node.
     * 
     * Time Complexity: O(n)
     *   - Visits each node exactly once
     * 
     * Space Complexity: O(h)
     *   - h = height of tree
     *   - O(log n) for balanced tree
     *   - O(n) for worst-case (unbalanced tree)
     */

//  So whenever we have to check whether a tree is a BST or not, we can use the same approach given the root we can
// find the max from and min from the left and right subtree and then check if the current node is greater than the 
//max of the left subtree and less than the min of the right subtree and secondly we have to find that its left 
//and right subtree are also BSTs
    bool isValid(TreeNode* root, long minvalue, long maxvalue) {
        // Base case: empty tree is always valid
        if (root == nullptr) {
            return true;
        }

        // Check current node value is strictly within allowed range
        if (root->val >= maxvalue || root->val <= minvalue) {
            return false;
        }

        // Recursively validate left subtree and right subtree
        bool leftN = isValid(root->left, minvalue, root->val);   // Left subtree: values < current node
        bool rightN = isValid(root->right, root->val, maxvalue); // Right subtree: values > current node

        // Return true only if both left and right subtrees are valid
        return leftN && rightN;
    }

    /*
     * Main function to check if a tree is a valid BST.
     * Starts the recursion with full valid range from LONG_MIN to LONG_MAX
     */
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};
