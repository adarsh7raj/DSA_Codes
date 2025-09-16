

// brute force approach but this will not work for large trees
//TC : O(n^2) where n is the number of nodes in the binary tree
//SC: O(n) where n is the number of nodes in the binary tree, due

class Solution {
public:
int maxi=INT_MIN;
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
    int max_sum(TreeNode* root){
        bool isbst=true;
        if(root==nullptr){
            return 0;
        }
      if(!isValid(root, LONG_MIN, LONG_MAX)){
        isbst=false;
      }
        
       int leftN=max_sum(root->left);
       int rightN=max_sum(root->right);
       
       if(!isbst){
        
        return 0;
       }
       maxi=max(maxi,leftN+rightN+root->val);
       return root->val + rightN + leftN;
  
        
    }
    int maxSumBST(TreeNode* root) {
        
        max_sum(root);
        if(maxi<0){
            return 0;
        }
        return maxi;
    }
};

// optimal solution
// So whenever we have to check whether a tree is a BST or not, we can use the same approach given the root we can
//find the max from and min from the left and right subtree and then check if the current node is greater than the 
// max of the left subtree and less than the min of the right subtree and secondly we have to find that its left and right subtree are also BSTs
// TC : O(n) where n is the number of nodes in the binary tree
// SC: O(h) where h is the height of the binary tree, due to recursion stack
class Solution {
    struct Info {
    
        int minVal;
        int maxVal;
        int sum;
    };

    int maxSum = 0;

    Info dfs(TreeNode* root) {
        if (!root) return { INT_MAX, INT_MIN, 0};

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        // Check if current tree is BST
        if (root->val > left.maxVal && root->val < right.minVal) {
            
            int currSum = left.sum + right.sum + root->val;
            maxSum = std::max(maxSum, currSum);

            return {

                min(left.minVal, root->val),
                max(right.maxVal, root->val),
                currSum
            };
        }

        // Not a BST
        return { INT_MIN, INT_MAX, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};


// this is the optimal solution it relies on these conditions : 
// 1.Its left subtree is a BST. 2.Its right subtree is a BST.
// 3.The maximum value in the left subtree is less than the current node's value.
// 4.The minimum value in the right subtree is greater than the current node's value.



#include <climits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    struct Info {
        bool isBST;
        long sum;
        int mn;
        int mx;
    };

    long best = 0;          // use long in case sums overflow int

    Info dfs(TreeNode* node) {
        if (!node) {
            return {true, 0, INT_MAX, INT_MIN}; // empty subtree: BST, neutral bounds
        }

        Info L = dfs(node->left);
        Info R = dfs(node->right);

        // check BST property
        if (L.isBST && R.isBST && node->val > L.mx && node->val < R.mn) {
            long curSum = L.sum + R.sum + node->val;
            if (curSum > best) best = curSum;
            return {true,
                    curSum,
                    std::min(L.mn, node->val),
                    std::max(R.mx, node->val)};
        }

        // not a BST
        return {false, 0, INT_MIN, INT_MAX};
    }

public:
    int maxSumBST(TreeNode* root) {
        best = 0;
        dfs(root);
        return (int)best;   // if spec wants 0 when all BST sums <=0 (LeetCode style)
    }

   
};
