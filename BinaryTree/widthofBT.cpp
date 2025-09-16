
// TC: O(n) where n is the number of nodes in the binary tree   
// SC : O(n)  The queue holds up to O(n) nodes in the worst case ;

 class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        // Queue holds node and its index in a complete binary tree
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long minIndex = q.front().second;  // index of first node at this level
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                // Normalize to prevent overflow
                index =index- minIndex;

                if (i == 0) first = index;
                if (i == size - 1) last = index;

                if (node->left)
                    q.push({node->left, 2 * index+1});
                if (node->right)
                    q.push({node->right, 2 * index + 2});
            }

            maxWidth = max(maxWidth, int(last - first + 1));
        }

        return maxWidth;
    }
};
