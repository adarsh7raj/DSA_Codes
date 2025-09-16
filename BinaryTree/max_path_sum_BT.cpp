


class Solution {
public:
    
    int maxSum;
    
    int solve(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        int neeche_hi_milgaya_answer = l + r + root->val; //(1)
        s
        int koi_ek_acha = max(l, r) + root->val; //(2)
        
        int only_root_acha = root->val; //(3)
        
        maxSum = max({maxSum, neeche_hi_milgaya_answer, koi_ek_acha, only_root_acha});
        
        
        //most important part
        return max(koi_ek_acha, only_root_acha);
        
    }
    
        int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        
        solve(root);
        
        return maxSum;
        
    }
};


// second approach// TC: O(n) because we are traversing all nodes once
// SC: O(n) because we are using vectors to store the elements


class Solution {
public:
    int maxSum = INT_MIN;

    int getMaxPath(TreeNode* root) {
        if (!root) return 0;

        // Get max sum from left and right subtree; if negative, treat as 0
        int left = max(0, getMaxPath(root->left));
        int right = max(0, getMaxPath(root->right));

        // Max path through this node
        int currentPathSum = root->val + left + right;

        // Update global maximum path sum
        maxSum = max(maxSum, currentPathSum);

        // Return max sum of path continuing from this node to one side
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        getMaxPath(root);
        return maxSum;
    }
};
