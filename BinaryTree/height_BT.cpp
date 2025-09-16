
// TC:O(n) where n is the number of nodes in the binary tree
// SC:O(n) for the queue and O(h) for the recursion stack where h is the height of the tree
// The height of the tree can be O(n) in the worst case (skewed tree),
// but O(log n) in the best case (balanced tree).
class Solution {
public:
int inorderTraversal(TreeNode* root, int size){
    if(root==nullptr){
        return size;
    }
    int left=inorderTraversal(root->left,size+1);
    int right=inorderTraversal(root->right,size+1);
    return max(left,right);
}
    int maxDepth(TreeNode* root) {
       
       return  inorderTraversal(root,0);
        
    }
};

// another approach using recursion
// TC: O(n) where n is the number of nodes in the binary tree
// In this approach, we traverse the tree recursively and calculate the height of each subtree.
// The height of a node is defined as the number of edges on the longest path from that
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) { // leaf node
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
};
