

// Intuition

// When deleting a node in a Binary Search Tree (BST), we must ensure the BST property remains valid after deletion. The BST property is:

// For every node, values in the left subtree are smaller, and values in the right subtree are larger.

// So, deletion needs to be handled carefully depending on how many children the target node has.

// Steps:

// Search for the node to delete
// Traverse the tree while keeping track of the parent pointer. If the key doesn’t exist, simply return the root.

// Case 1: Node has no children (leaf node)

// Just remove the node by updating the parent’s pointer to nullptr.

// If the node is the root, the tree becomes empty.

// Case 2: Node has one child

// Replace the node with its single child.

// Update the parent’s pointer accordingly.

// If the node is the root, the child becomes the new root.

// Case 3: Node has two children

// This is the tricky part. We need to find a replacement that keeps the BST valid.

// We can choose either:

// Inorder Predecessor (the maximum value in the left subtree)

// Inorder Successor (the minimum value in the right subtree)

// Your code chooses the inorder predecessor.

// Process:

// Copy the predecessor’s value into the current node.

// Delete the predecessor node (which will have at most one child).

// This way, the BST property is preserved in all cases.

// 📝 Algorithm

// Find the node:

// Start from the root.

// Traverse left or right based on whether key < curr->val or key > curr->val.

// Keep track of the parent pointer.

// If the node is not found, return root.

// Delete node cases:

// Case 1 (No children):

// If curr is a leaf, set parent’s left/right = nullptr.

// If deleting root, set root = nullptr.

// Case 2 (One child):

// Find the child (curr->left or curr->right).

// Replace curr with its child in the parent’s pointer.

// If deleting root, update root to child.

// Case 3 (Two children):

// Find inorder predecessor = max node in curr->left.

// Start at curr->left and go as far right as possible.

// Copy predecessor’s value into curr.

// Delete the predecessor node (which has at most one child).

// Return root after deletion.





class Solution {
public:
    TreeNode* deleteNode(TreeNode* root,int key) {
    TreeNode* parent = nullptr;
    TreeNode* curr = root;

    // 1) find the node
    while (curr && curr->val != key) {
        parent = curr;
        if (key < curr->val) curr = curr->left;
        else curr = curr->right;
    }
    if (!curr) {
        return root;
        }

        // key not found

    // 2) Case: no children
    if (!curr->left && !curr->right) {
        if (!parent) root = nullptr;
        else if (parent->left == curr) parent->left = nullptr;
        else parent->right = nullptr;
        delete curr;
        return root;
    }

    // 3) Case: one child
    if (!curr->left || !curr->right) {
        TreeNode* child = curr->left ? curr->left : curr->right;
        if (!parent) root = child;               // IMPORTANT: updating root when deleting root
        else if (parent->left == curr) parent->left = child;
        else parent->right = child;
        delete curr;
        return root;
    }

    // 4) Case: two children — use inorder predecessor (max in left subtree)
    TreeNode* predParent = curr;
    TreeNode* pred = curr->left;
    while (pred->right) {
        predParent = pred;
        pred = pred->right;
    }

    // Copy predecessor value into current node
    curr->val = pred->val;

    // Remove predecessor node (pred has no right child, may have left child)
    TreeNode* predChild = pred->left;
    if (predParent->right == pred)
        predParent->right = predChild;
    else
        predParent->left = predChild; // occurs when predParent == curr

    delete pred;
    return root;
}

};