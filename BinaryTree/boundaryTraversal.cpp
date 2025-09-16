
// this is an ugly code but it works fine
// it is a boundary traversal of binary tree
// TC: O(n) because we are traversing all nodes once
// SC: O(n) because we are using vectors to store the elements
class Solution {
  public:
  void leftNode(Node*root,vector<int>& leftElements){
      if(root==nullptr){
          return;
      }
      if(root->left==nullptr &&root->right==nullptr ){
          return;
      }
       leftElements.push_back(root->data);
      if(root->left!=nullptr){
           leftNode(root->left,leftElements);
      }
     else{
          leftNode(root->right,leftElements);
     }
     
      
  }
void leafNode(Node*root,vector<int>&leafElements){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr){
        leafElements.push_back(root->data);
    }
    leafNode(root->left,leafElements);
    leafNode(root->right,leafElements);
}
void rightNode(Node*root,vector<int>& rightElements,Node*curr){
    if(root==nullptr){
          return;
}
if(root->left==nullptr && root->right==nullptr){
    return;
}
if(root->right!=nullptr){
    rightNode(root->right,rightElements,curr);
}
else{
    rightNode(root->left,rightElements,curr);
}
     
    if(curr!=root){
     rightElements.push_back(root->data);
}
    }
      
vector<int> traversal(Node* root){
  
    Node* curr=root;
    vector<int>ans;
      if(root==nullptr){
        return ans;
    }
    if(root->left==nullptr && root->right==nullptr){
        ans.push_back(root->data);
        return ans;
    }
    vector<int>leftElements;
    vector<int>leafElements;
    vector<int>rightElements;
    if(root->left!=nullptr){
         
        leftNode(root,leftElements);
    }
    else{
        ans.push_back(root->data);
    }
  
   //leftElements.pop_back();
   leafNode(root,leafElements);
   if(root->right!=nullptr){
       rightNode(root,rightElements,curr);
   }
   
   //rightElements.pop_back();
  // reverse(rightElements.begin(),rightElements.end());
   for(auto it:leftElements){
       ans.push_back(it);
   }
   for(auto it:leafElements){
       ans.push_back(it);
   }
   for(auto it:rightElements){
       ans.push_back(it);
   }
   return ans;
}
    


    vector<int> boundaryTraversal(Node *root) {
        // code here
   vector<int>ans=traversal(root);
  
 return ans;
    }
};


// better code// this is a better code for boundary traversal of binary tree
// it is more readable and efficient

class Solution {
  public:

  void leftBoundary(Node* root, vector<int>& res) {
      if (!root || (!root->left && !root->right)) return;
      res.push_back(root->data);
      if (root->left) leftBoundary(root->left, res);
      else leftBoundary(root->right, res);
  }

  void rightBoundary(Node* root, vector<int>& res) {
      if (!root || (!root->left && !root->right)) return;
      if (root->right) rightBoundary(root->right, res);
      else rightBoundary(root->left, res);
      res.push_back(root->data);  // reverse order
  }

  void leaves(Node* root, vector<int>& res) {
      if (!root) return;
      leaves(root->left, res);
      if (!root->left && !root->right) res.push_back(root->data);
      leaves(root->right, res);
  }

  vector<int> boundaryTraversal(Node *root) {
      vector<int> res;
      if (!root) return res;
      
      if (!(root->left == nullptr && root->right == nullptr))
          res.push_back(root->data);  // root is not leaf
      
      leftBoundary(root->left, res);
      leaves(root, res);
      rightBoundary(root->right, res);
      
      return res;
  }
};
