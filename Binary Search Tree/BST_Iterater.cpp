

// brute force approach

// TC of next() and hasNext() is o(1);
// SC : O(n) where n is the number of nodes in the binary tree, due to the storage of inorder traversal in a vector
// This solution is not optimal for the BST iterator problem, as it uses extra space to store
class BSTIterator {
public:
int count;
vector<int>ans;
int n;
  void Inorder(TreeNode* root,vector<int>  & ans){
     if(root==nullptr){
            return ;
        }
       Inorder(root->left,ans);
         ans.push_back(root->val);
         Inorder(root->right,ans);
    }
    BSTIterator(TreeNode* root) {
   
       Inorder(root,ans);
       count=0;
        n=ans.size();
    }
    
    int next() {
        int result=ans[count];
        count++;
        return result;
    }
    
    bool hasNext() {
        if(count==n){
            return false;
        }
        return true;
    }
};

// another brute force approach : 

// TC of next() and hasNext() is O(n) where n is the number of nodes in the binary tree
// SC : O(n) where n is the number of nodes in the binary tree
class BSTIterator {
public:
int count=1;
int data=0;
int n=0;
TreeNode*temp=nullptr;
  int length(TreeNode* root) {
    if (root == nullptr) {
      
        return 0;  // or return -1 if you count edges instead of nodes
    } else {
        int left_height = length(root->left);
        int right_height = length(root->right);
        return 1 + (left_height+ right_height);
    }
}
  void Inorder(TreeNode* root,int count,int &k){
     if(root==nullptr){
         k++;
            return ;
        }
       Inorder(root->left,count,k);
        if(count==k){
            data=root->val;
            k++;
            return;
        }
         Inorder(root->right,count,k);
    }
    BSTIterator(TreeNode* root) {
   n=length(root);
     temp=root;
        
    }
    
    int next() {
        int k=0;
       Inorder(temp,count,k);
        count++;
        return data;
    }
    
    bool hasNext() {
     if(n==count-1){
        return false;
     }
        return true;
    }
};






// optimal solution :

// TC of next() and hasNext() is O(1) where h is the height of the binary tree
// SC : O(h) where h is the height of the binary tree, due to the storage of the current node in a stack

class BSTIterator {
    stack<TreeNode*> leftmost,rightmost; // Stack to hold the path to the next node

    // Helper to push all left children
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
public:
    // Constructor
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    // Returns the next smallest element in the BST
    int next() {
        TreeNode* node = leftmost.top();
        st.pop();
        // If there is a right subtree, push all its left children
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }
     int before() {
        TreeNode* node = rightmost.top();
        rightmost.pop();
        push_all_right(node->left);
        return node->val;
    }
    
    // Returns true if there is a next smallest number
    bool hasNext() {
        return !st.empty();
    }
};
