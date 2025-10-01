
// brute force approach
// TC : O(n*h) where n is the number of nodes in the binary tree and h is the height of the binary tree
// SC: O(h) where h is the height of the binary tree, due to storing
class Solution {
public:
TreeNode* construct(TreeNode*  root,int data){
    if(root==nullptr){
        TreeNode* temp=new TreeNode(data);
        return temp;
    }
    if(root->val>data){
        root->left=construct(root->left,data);
    }
    else{
        root->right=construct(root->right,data);
    }
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=nullptr;
        for(int i=0;i<preorder.size();i++){
            root=construct(root,preorder[i]);
            cout<<root->val;
        }
        
        return root;
    }
};

// optimal solution

// TC : O(n) where n is the number of nodes in the binary tree
// SC: O(h) where h is the height of the binary tree, due to storing

// 🌟 Intuition

// When given a preorder traversal (root → left → right), the first element is always the root.

// For a BST:

// The left subtree must contain values smaller than the root.

// The right subtree must contain values greater than the root, but also must respect any upper bound from ancestors.

// The clever trick here is to use a bound to control where a subtree ends:

// Every recursive call has an upper limit (bound).

// If the next value in preorder is greater than bound, it cannot belong in this subtree → return nullptr.

// Otherwise, create a node and recursively build left and right subtrees.

// This way, each node is placed in its correct position without repeatedly traversing the tree, unlike the naive insertion approach.

// 📝 Algorithm

// Start with index i=0 (first element of preorder) and initial bound = INT_MAX.

// Define a recursive function construct(preorder, i, bound):

// If i == preorder.size() → all nodes processed → return nullptr.

// If preorder[i] > bound → current value is too large for this subtree → return nullptr.

// Otherwise:

// Create a node with preorder[i].

// Increment i to move to the next element.

// Recursively build the left subtree with new bound = root->val (everything left must be < root).

// Recursively build the right subtree with the same bound passed down from the parent (everything right must be < parent’s bound).

// Continue until all elements are used.

// Return the constructed tree.
class Solution {
public:
TreeNode* construct(vector<int>& preorder,int & i,int bound){
    if(preorder.size()==i || preorder[i]>bound){
        return nullptr;
    }
    TreeNode* root=new TreeNode(preorder[i]);
    i++;
    root->left=construct(preorder,i,root->val);
    root->right=construct(preorder,i,bound);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
       return construct(preorder,i,INT_MAX);
       
    }
};

// another approach carrying min and max values(optimal solution)
// TC : O(n) where n is the number of nodes in the binary tree
// SC: O(h) where h is the height of the binary tree, due to storing


class Solution{
    public:
    
TreeNode* construct(vector<int>& preorder, int &i, int minVal, int maxVal) {
    if (i == preorder.size()) return nullptr;

    int val = preorder[i];
    if (val <= minVal || val >= maxVal) return nullptr;

    TreeNode* root = new TreeNode(val);
    i++;

    root->left = construct(preorder, i, minVal, val);   // Left subtree: values < root
    root->right = construct(preorder, i, val, maxVal);  // Right subtree: values > root

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return construct(preorder, i, INT_MIN, INT_MAX);
}

};
