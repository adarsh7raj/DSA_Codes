
// this code only works if inorder[i] elements and preorder[i] elements are unique
  
  class Solution {
public:
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if(start > end)
            return NULL;
        
        int rootVal = preorder[idx];
       int k;
        
        for(int i=0; i <= inorder.size(); i++) {
            if(inorder[i] == rootVal){
                k=i;
                       break;
            }
              
        }
        
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        root->left  = solve(preorder, inorder, start, k-1, idx);
        root->right = solve(preorder, inorder, k+1, end, idx);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        int idx = 0;
        
        return solve(preorder, inorder, 0, n-1, idx);
    }
};


// optimal approach beacause we are using a map to store the indices of inorder elements
// TC: O(n) because we are traversing all nodes once
class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int l, int r, int& idx) {
        if(l > r)
            return NULL;
        
        int rootVal = preorder[idx];
        idx++;
        int i = mp[rootVal];
        
        TreeNode* root = new TreeNode(rootVal);
        root->left     = construct(preorder, inorder, l, i-1, idx);
        root->right    = construct(preorder, inorder, i+1, r, idx);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();
        int n = preorder.size();
        for(int i = 0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        
        int idx = 0;
        return construct(preorder, inorder, 0, n-1, idx);
    }
};