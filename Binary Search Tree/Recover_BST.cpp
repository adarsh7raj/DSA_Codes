
// brute force approach

// TC : O(n log n) where n is the number of nodes in the binary tree
// SC: O(n) where n is the number of nodes in the binary tree, due to storing nodes in an array
class Solution {
public:
void inorder(TreeNode* root,vector<TreeNode*>& arr){
    if(root==nullptr){
        return ;
    }
    inorder(root->left,arr);
    arr.push_back(root);
    inorder(root->right,arr);
}
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>arr;
        inorder(root,arr);
        vector<int>temp;
        for(int i=0;i<arr.size();i++){
            temp.push_back(arr[i]->val);

        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<arr.size();i++){
          arr[i]->val=temp[i];
        }

    }
};
// optimal solution
// So basically there are two cases : first one is where adjacent nodes are swapped and second one
// is where non-adjacent nodes are swapped.
// adjacent nodes swapped : 1,3,2,4,5
// non-adjacent nodes swapped : 1,5,3,4,2
// Intuition Development (The "Story")

// Step 1: Think about inorder property

// If no nodes are swapped → inorder is sorted.

// If two nodes are swapped → inorder will have exactly two “drops” (places where the order breaks).

// Example: [1, 4, 3, 2, 5]

// Drop between 4 > 3

// Drop between 3 > 2
// → The swapped nodes are 4 and 2.

// Step 2: How to detect these “drops”

// Traverse the tree inorder.

// Keep track of the previous node (prev).

// If prev->val > root->val, we’ve found a violation.

// Step 3: Handling first and second violation

// First violation: mark first = prev.

// Second violation (or update): mark second = root.

// At the end, we have first and second.

// Step 4: Fix the tree

// Just swap the values of first and second.

// 📝 Algorithm

// Initialize first = nullptr, second = nullptr, prev = INT_MIN node.

// Perform an inorder traversal of the tree.

// At each node:

// If prev->val > root->val:

// If first is not set → set first = prev.

// Always set second = root.

// Update prev = root.

// After traversal, swap first->val and second->val.

// ⏱️ Complexity

// Time: O(n) (we traverse each node once).

// Space: O(h) (recursion stack, where h is tree height).


class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Detect where inorder property breaks
        if (prev && prev->val > root->val) {
            first = prev;   // first wrong node
            second = root;              // second wrong node (can update multiple times)
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};

