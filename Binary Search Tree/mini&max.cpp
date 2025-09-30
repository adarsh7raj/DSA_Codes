// to find  maximum value in a BST
class Solution {
  public:
    int maxValue(Node* root) {
        // Code here
        int ans=-1;
        while(root!=nullptr){
            ans=root->data;
            root=root->right;
        }
        return ans;
    }
};

// to find  minimum value in a BST
class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        int ans=-1;
        while(root!=nullptr){
            ans=root->data;
            root=root->left;
        }
        return ans;
    }
};