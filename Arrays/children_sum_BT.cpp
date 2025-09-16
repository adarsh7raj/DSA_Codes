


class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isEqual(Node* root){
        if(root==nullptr){
            return 1;
        }
        if(root->left==nullptr && root->right==nullptr){
            return 1;
        }
        int leftChild=0;
        int rightChild=0;
        
        if(root->left!=nullptr){
            leftChild=root->left->data;
        }
        if(root->right!=nullptr){
            rightChild=root->right->data;
        }
        
        if(leftChild+rightChild !=root->data){
            return 0;
        }
        int leftN=isEqual(root->left);
        int rightN=isEqual(root->right);
        if(leftN && rightN){
            return 1;
        }
        return 0;
    }
    int isSumProperty(Node *root) {
        // Add your code here
      
        return isEqual(root);
    }
};

