// Intuition

// In a binary tree, each node knows only about its left and right child, but not its parent.

// To move “upwards” from a node (towards its parent), we need a parent map.

// Once we have the parent map, the problem reduces to:

// Do a BFS starting from the target node,

// Traverse in 3 directions: left child, right child, and parent,

// Stop after k levels of BFS.

// This guarantees we explore all nodes that are exactly at distance k from the target.

// 📝 Algorithm

// Build parent map

// Traverse the tree and map each node to its parent.

// This allows moving upwards in BFS.

// BFS from target node

// Use a queue to do level-order traversal.

// Track visited nodes (using a set) to avoid revisiting the same node.

// For each level, expand neighbors: left child, right child, and parent.

// After k levels, all nodes in the queue are exactly distance k.

// Collect results

// Extract values of all nodes remaining in the queue when distance = k.
class Solution {
public:
    // Step 1: Build a parent map for each node
    void inorder(TreeNode* root, map<TreeNode*, TreeNode*>& parent) {
        if (root == nullptr) return;

        if (root->left != nullptr) {
            parent[root->left] = root;       // left child -> parent
            inorder(root->left, parent);
        }
        if (root->right != nullptr) {
            parent[root->right] = root;      // right child -> parent
            inorder(root->right, parent);
        }
    }

    // Step 2: BFS starting from target node
    void bfs(TreeNode* target, int k, map<TreeNode*, TreeNode*>& parent, vector<int>& ans) {
        unordered_set<TreeNode*> visited;    // mark visited nodes (avoid revisits)
        queue<TreeNode*> q;

        q.push(target);
        visited.insert(target);

        // BFS by levels
        while (!q.empty() && k > 0) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Explore left child
                if (curr->left && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }

                // Explore right child
                if (curr->right && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }

                // Explore parent
                if (parent.count(curr) && !visited.count(parent[curr])) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
            k--;  // after finishing one level, decrement k
        }

        // Now all nodes in the queue are at distance K
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
    }

    // Main function
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent;   // parent map
        vector<int> ans;

        inorder(root, parent);              // build parent mapping
        bfs(target, k, parent, ans);        // BFS from target node

        return ans;
    }
};
