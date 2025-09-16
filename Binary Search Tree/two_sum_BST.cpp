

// brute force approach
// TC : O(n^2) where n is the number of nodes in the binary tree
// SC: O(n) where n is the number of nodes in the binary tree, due
class Solution {
public:
 void Inorder(TreeNode* root,vector<int>  & ans){
     if(root==nullptr){
            return ;
        }
       Inorder(root->left,ans);
         ans.push_back(root->val);
         Inorder(root->right,ans);
    }

    bool findTarget(TreeNode* root, int k) {
     vector<int>ans;
     Inorder(root,ans);
     for(int i=0;i<ans.size();i++){
        for(int j=i+1;j<ans.size();j++){
            if(ans[i]+ans[j]==k){
                return true;
            }
        }
     }
     return false;
    }
};


//

class Solution {
public:
    stack<TreeNode*> leftmost, rightmost;

    // Push all leftmost nodes onto the stack
    void push_all_left(TreeNode* root) {
        while (root) {
            leftmost.push(root);
            root = root->left;
        }
    }

    // Push all rightmost nodes onto the stack
    void push_all_right(TreeNode* root) {
        while (root) {
            rightmost.push(root);
            root = root->right;
        }
    }

    bool findTarget(TreeNode* root, int k) 
    {
        if (!root) return false;
        
        push_all_left(root);
        push_all_right(root);

        while (!leftmost.empty() && !rightmost.empty() && leftmost.top() != rightmost.top()) 
        {
            int left_val = leftmost.top()->val;
            int right_val = rightmost.top()->val;
            int sum = left_val + right_val;

            if (sum == k) 
            {
                return true;
            } 
            else if (sum < k) 
            {
                // Move left iterator forward
                TreeNode* node = leftmost.top();
                leftmost.pop();
                push_all_left(node->right);
            } 
            else 
            {
                // Move right iterator backward
                TreeNode* node = rightmost.top();
                rightmost.pop();
                push_all_right(node->left);
            }
        }
        return false;
    }
};

// optimal solution

// TC of next() and before() is O(1) where h is the height of the binary tree
// SC : O(h) where h is the height of the binary tree, due to the
class Solution {
public:
    stack<TreeNode*> leftmost, rightmost;

    void push_all_left(TreeNode* root) {
        while (root) {
            leftmost.push(root);
            root = root->left;
        }
    }

    void push_all_right(TreeNode* root) {
        while (root) {
            rightmost.push(root);
            root = root->right;
        }
    }
// this will return the next smallest element in the BST
// this is like BST elements in ascending order
    int next() {
        TreeNode* node = leftmost.top();
        leftmost.pop();
        push_all_left(node->right);
        return node->val;
    }
// this will return the previous largest element in the BST
// this is like BST elements in descending order
    int before() {
        TreeNode* node = rightmost.top();
        rightmost.pop();
        push_all_right(node->left);
        return node->val;
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        push_all_left(root);
        push_all_right(root);

        int i = next();
        int j = before();

        // Use i < j only for no duplicates
        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) i = next();
            else j = before();
        }
        return false;
    }
};
