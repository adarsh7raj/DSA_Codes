

// brute force solution

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  int maxi=INT_MIN;
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
      bool isValid(Node* root, long minvalue, long maxvalue) {
        // Base case: empty tree is always valid
        if (root == nullptr) {
            return true;
        }

        // Check current node value is strictly within allowed range
        if (root->data >= maxvalue || root->data <= minvalue) {
            return false;
        }

        // Recursively validate left subtree and right subtree
        bool leftN = isValid(root->left, minvalue, root->data);   // Left subtree: values < current node
        bool rightN = isValid(root->right, root->data, maxvalue); // Right subtree: values > current node

        // Return true only if both left and right subtrees are valid
        return leftN && rightN;
    }
    int height(Node* root) {
        if (root == nullptr) { // leaf node
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + leftHeight + rightHeight;
    }
    void inorder(Node* root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
       bool isbst= isValid(root,LONG_MIN,LONG_MAX);
       if(isbst){
           int height_tree=height(root);
          
           maxi=max(maxi,height_tree);

       }
       inorder(root->right);
    }
    int largestBst(Node *root) {
        // Your code here
        inorder(root);
        return maxi;
        
    }
};

//optimal solution
// We want to find the largest BST inside a binary tree.

// A BST (Binary Search Tree) has a strict property:

// All nodes in left subtree < root < All nodes in right subtree


// So for every subtree, if we know:

// Whether its left subtree is a BST

// Whether its right subtree is a BST

// The maximum value in the left subtree

// The minimum value in the right subtree

// Then we can check if the current node’s subtree is also a BST.

// 👉 If yes → compute its size as left.size + right.size + 1.
// 👉 If not → largest BST is the max of left or right subtree sizes.

// This is exactly what the code is doing with the Info struct.

// 🔹 The Info struct
// struct Info {
//     bool isBST;  // Is this subtree a BST?
//     int size;    // Size of the largest BST in this subtree
//     int minVal;  // Minimum value in this subtree
//     int maxVal;  // Maximum value in this subtree
// };


// Each recursive call returns an Info object that describes the subtree rooted at root.

// 🔹 Role of minVal and maxVal

// Think of them as "boundary markers" for the subtree.

// minVal → the smallest node value in the current subtree.
// Why? Because when a parent node compares with its right child, it must know that parent < right.minVal.

// maxVal → the largest node value in the current subtree.
// Why? Because when a parent node compares with its left child, it must know that parent > left.maxVal.

// These values flow upward so every ancestor can validate the BST property correctly.

// 🔹 Why do we do these lines?
// curr.minVal = min(root->val, left.minVal);
// curr.maxVal = max(root->val, right.maxVal);

// 🔸 For minVal:

// In a BST, the minimum of the whole subtree rooted at root must be either:

// the left subtree’s minimum (if left exists), or

// the root’s value (if no left child).

// So min(root->val, left.minVal) gives the correct minimum.

// 🔸 For maxVal:

// In a BST, the maximum of the whole subtree rooted at root must be either:

// the right subtree’s maximum (if right exists), or

// the root’s value (if no right child).

// So max(root->val, right.maxVal) gives the correct maximum.

// ⚡ Notice we don’t use right.minVal in minVal and don’t use left.maxVal in maxVal.
// That’s because if the BST condition holds, the smallest value must always come from the left side (or root), and the largest from the right side (or root).

// 🔹 Algorithm (step by step)

// Base case: If node is nullptr, return

// isBST = true (empty tree is BST)
// size = 0
// minVal = INT_MAX (so min() works properly)
// maxVal = INT_MIN (so max() works properly)


// Recursive calls: Get info for left and right subtrees.

// Check BST property:

// Left subtree must be BST

// Right subtree must be BST

// root->val > left.maxVal

// root->val < right.minVal

// If valid BST:

// Mark current as BST

// size = left.size + right.size + 1

// Update minVal and maxVal as explained

// Update maxSize global answer

// If not BST:

// Mark current as not BST

// Keep size = max(left.size, right.size) (largest BST inside children)

// Return the Info struct to the parent.

// 🔹 Example Walkthrough

// Tree:

//         10
//        /  \
//       5    15
//      / \   / \
//     1   8 12  20


// Leaf node(1): {true, 1, 1, 1}

// Leaf node(8): {true, 1, 8, 8}

// Node(5):

// left={true,1,1,1}, right={true,1,8,8}

// check: 1 < 5 < 8 ✅

// size=3, minVal=1, maxVal=8

// Node(12): {true, 1, 12, 12}

// Node(20): {true, 1, 20, 20}

// Node(15):

// left={true,1,12,12}, right={true,1,20,20}

// check: 12 < 15 < 20 ✅

// size=3, minVal=12, maxVal=20

// Node(10):

// left={true,3,1,8}, right={true,3,12,20}

// check: 8 < 10 < 12 ✅

// size=7, minVal=1, maxVal=20

// Answer = 7

// ✅ In short:

// minVal and maxVal are "boundary markers" used by ancestors to check BST validity.

// We compute them as min(root->val, left.minVal) and max(root->val, right.maxVal) because in a BST, the smallest must come from the left side, and the largest from the right side.

// The algorithm is bottom-up, checking BST property and size at each step.
struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

class Solution {
public:
    Info helper(TreeNode* root, int& maxSize) {
        if (!root) return {true, 0, INT_MAX, INT_MIN};

        Info left = helper(root->left, maxSize);
        Info right = helper(root->right, maxSize);

        Info curr;

        // Case: valid BST
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            curr.isBST = true;
            curr.size = left.size + right.size + 1;
            curr.minVal = min(root->val, left.minVal);
            curr.maxVal = max(root->val, right.maxVal);

            maxSize = max(maxSize, curr.size);
            return curr;
        }

        // Case: not BST
        curr.isBST = false;
        curr.size = max(left.size, right.size);
        return curr;
    }

    int largestBSTSubtree(TreeNode* root) {
        int maxSize = 0;
        helper(root, maxSize);
        return maxSize;
    }
};
