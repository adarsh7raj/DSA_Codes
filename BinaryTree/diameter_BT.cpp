

// TC : O(n) where n is the number of nodes in the binary tree.
// SC :O(n) for the recursion stack 

class Solution {
public:
    int maxDiameter = 0;

    int getDepth(TreeNode* root) {
        if (!root) return 0;

        int left = getDepth(root->left);
        int right = getDepth(root->right);

        maxDiameter = max(maxDiameter, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        return maxDiameter;
    }
};
