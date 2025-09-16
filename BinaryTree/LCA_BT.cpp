// this works but fails for large inputs like p=9998 and q=9999 MLE
//TC: O(n^2) because O(n) for traversing each and every node and at each call as ans is passed by value it's copy is being made 
// at each call so it takes O(n) time to copy the vector ans

//SC: O(n^2) where n is the number of nodes in the binary tree

class Solution {
public:
void InorderTraversal(TreeNode*root,  map<TreeNode*,vector<TreeNode*>>& mp,vector<TreeNode*>ans){
if(root==nullptr){
    return;
}
ans.push_back(root);
mp[root]=ans;   
InorderTraversal(root->left,mp,ans);
InorderTraversal(root->right,mp,ans);
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*,vector<TreeNode*>>mp;
        vector<TreeNode*>ans;
       InorderTraversal(root,mp,ans); 

      vector<TreeNode*>p_ancestors=mp[p];
      vector<TreeNode*>q_ancestors=mp[q];
      reverse(p_ancestors.begin(),p_ancestors.end());
      reverse(q_ancestors.begin(),q_ancestors.end());
      unordered_set<TreeNode*>st;
     for(auto it:p_ancestors){
        st.insert(it);
     }
    
      for(auto it:q_ancestors){
        if(st.count(it)){
            return it;
        }
      }
      return nullptr;
    }
};


// TC : O(n) where n is the number of nodes in the binary tree
// SC: O(h) where h is the height of the binary tree, due to recursion stack space
// This is the optimal solution for finding the lowest common ancestor in a binary tree.
class Solution {
public:
  
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==nullptr){
        return nullptr;
       }
       if(root==p){
        return p;
       }
       if(root==q){
        return q;
       }
       TreeNode* leftN=lowestCommonAncestor(root->left,p,q);
       TreeNode* rightN=lowestCommonAncestor(root->right,p,q);
       if(leftN!=nullptr && rightN!=nullptr){
   return root;
       }
       if(leftN==nullptr){
        return rightN;
       }
       if(rightN==nullptr){
        return leftN;
       }
return nullptr;
    }
};


