class Solution {
public:

// 🌟 Intuition

// The problem is to check whether a given binary tree is a valid Binary Search Tree (BST).
// A BST has this property:

// For every node:

// All values in its left subtree must be strictly less than the node’s value.

// All values in its right subtree must be strictly greater than the node’s value.

// And this condition must hold true for every node in the tree.

// Now, if we only check the immediate children of a node, it’s not enough.
// 👉 Example:

//        10
//       /  \
//      5    15
//          /  \
//         6    20


// At node 15, the left child is 6, which is less than 15, so it seems okay. But 6 is not greater than 10 (root). This violates the BST property.

// So, we need a way to carry bounds (minimum and maximum values allowed) for each node as we traverse.

// At root, valid range = (-∞, +∞).

// When we go left, we tighten the upper bound (max = parent’s value).

// When we go right, we tighten the lower bound (min = parent’s value).

// At each node, we check:

// If node->val is not strictly inside (min, max), return false.

// Recursively check both subtrees with updated bounds.

// This guarantees that the tree satisfies the BST property everywhere.

// 📝 Algorithm

// Start at the root with range (LONG_MIN, LONG_MAX).

// If the node is nullptr, return true (empty tree is valid).

// Check if root->val lies in the valid range (minvalue, maxvalue).

// If not, return false.

// Recursively check:

// Left subtree with range (minvalue, root->val)

// Right subtree with range (root->val, maxvalue)

// If both subtrees are valid, return true. Otherwise, return false.

// ✅ Example Walkthrough

// Take the valid BST:

//        10
//       /  \
//      5    15
//          /  \
//         12   20


// At root (10): range = (-∞, ∞) ✅

// Left child (5): range = (-∞, 10) → 5 < 10 ✅

// Right child (15): range = (10, ∞) → 15 > 10 ✅

// Left child of 15 (12): range = (10, 15) → ✅

// Right child of 15 (20): range = (15, ∞) → ✅
// All nodes satisfy → BST valid.

// ⏱ Complexity

// Time Complexity: O(N) (we visit every node once).

// Space Complexity: O(H) where H = height of tree (recursion stack). Worst case (skewed tree) → O(N).
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
