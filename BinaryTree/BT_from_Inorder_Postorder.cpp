
//all we need to do is to reverse the postorder vector and then use the same logic as in the inorder 
//and preorder case only change we need to do is to first traverse the right subtree and then the left subtree
// TC: O(n) because we are traversing all nodes once
// SC: O(n) because we are using vectors to store the elements


class Solution {
public:
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end, int& idx) {
        if(start > end)
            return NULL;
        
        int rootVal = postorder[idx];
        int i = start;
        
        for(; i <= end; i++) {
            if(inorder[i] == rootVal)
                break;
        }
        
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        // first traverse the right subtree because we are using postorder.
        root->right = solve(inorder, postorder, i+1, end, idx);
        root->left  = solve(inorder, postorder, start, i-1, idx);
        
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        reverse(postorder.begin(),postorder.end());
        int idx = 0;
        
        return solve(inorder, postorder, 0, n-1, idx);
    }
};
