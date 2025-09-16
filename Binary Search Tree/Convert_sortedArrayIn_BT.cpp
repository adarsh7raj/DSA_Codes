


class Solution {
public:
 
    TreeNode* solve(vector<int>& inorder, int start, int end) {
        if(start > end){
            return nullptr;
        }
    int mid = (end + start) / 2;

     
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left  = solve(inorder, start, mid-1);
        root->right = solve( inorder, mid+1, end);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
      return solve(nums,0,n-1);

 
    }
};