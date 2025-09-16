

// C++ code to find all root-to-leaf paths in a binary tree.
// Each path is represented as a string of node values separated by "->". LeetCode question

class Solution {
public:

void totalpaths(TreeNode * root,vector<string>& ans,string result){
 if(root==nullptr){
   
    return;
 }
 if(!result.empty()){
    result+="->";
 }
 result=result+to_string(root->val);
 if(root->left==nullptr && root->right==nullptr){
    ans.push_back(result);
    return ;
 }

        totalpaths(root->left,ans,result);
        totalpaths(root->right,ans,result);
        
     
 }

    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string>ans;
          string result;
            totalpaths(root,ans,result);
            return ans;
        
    }
};
//
// The above code uses recursion to traverse the binary tree and find all paths from root to leaf nodes.
// It constructs each path as a string and stores it in the `ans` vector.
// Geeks for Geeks question
// when passing the result by value we do need to do backtracking:

// 

class Solution {
  public:
  void totalpaths(Node * root,vector<vector<int>>& ans,vector<int> result){
 if(root==nullptr){
   
    return;
 }
 result.push_back(root->data);
 if(root->left==nullptr && root->right==nullptr){
    ans.push_back(result);
    return;
 }

        totalpaths(root->left,ans,result);
        totalpaths(root->right,ans,result);
     
 }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
            vector<int>result;
            totalpaths(root,ans,result);
            return ans;
    }
};

// when passing the result by reference we need to do backtracking:

class Solution {
  public:
  void totalpaths(Node * root,vector<vector<int>>& ans,vector<int> &result){
 if(root==nullptr){
   
    return;
 }
 result.push_back(root->data);
 if(root->left==nullptr && root->right==nullptr){
    ans.push_back(result);
  
 }
else{
totalpaths(root->left,ans,result);
        totalpaths(root->right,ans,result);
}
    result.pop_back(); // backtrack 
        
     
 }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
            vector<int>result;
            totalpaths(root,ans,result);
            return ans;
    }
};