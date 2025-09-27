

/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
  int mini=INT_MAX;
  int maxi=INT_MIN;
  void preorder(Node* root,bool is_find_min){
      if(root==nullptr){
          return ;
      }
      if(is_find_min){
             mini= min(mini,root->data);  
      }
      else{
         maxi= max(maxi,root->data);
      }

      preorder(root->left,is_find_min);
      preorder(root->right,is_find_min);
  }
    int findMax(Node *root) {
        // code here
        preorder(root,0);
        return maxi;
        
    }

    int findMin(Node *root) {
        
        // code here
        preorder(root,1);
        return mini;
    }
};