

// brute force approach
// TC : O(n) where n is the number of nodes in the binary tree
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

    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        Inorder(root,ans);
        return ans[k-1];
    }
  
};

// optimal solution
//TC : O(n) 
//SC : O(h) where h is the height of the binary tree, due to recursion stack
// We solve this problem with SC in O(1) using Morris Traversal, but here we are using recursion for simplicity
// Morris Traversal is a way to traverse a binary tree without using recursion or a stack


class Solution {
public:
 void Inorder(TreeNode* root,int & count ,int k,int & data ){
     if(root==nullptr){
        count++;
            return ;
        }
       Inorder(root->left,count,k,data);
         if(count==k){
            data=root->val;
            count++;
            return ;
         }
         Inorder(root->right,count,k,data);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        int data;
        int count=0;
        Inorder(root,count,k,data);
        return data;
    }
  
};