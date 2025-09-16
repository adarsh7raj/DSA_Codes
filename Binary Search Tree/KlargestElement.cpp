/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
  int length(Node* root) {
    if (root == nullptr) {
      
        return 0;  // or return -1 if you count edges instead of nodes
    } else {
        int left_height = length(root->left);
        int right_height = length(root->right);
        return 1 + (left_height+ right_height);
    }
}
  
  void Inorder(Node* root,int & count ,int k,int & data ){
     if(root==nullptr){
         count++;
            return ;
        }
       Inorder(root->left,count,k,data);
         
         if(count==k){
            data=root->data;
            count++;
            return ;
         }
         Inorder(root->right,count,k,data);
    }

    int kthLargest(Node *root, int k) {
        // Your code here
          int data;
        int count=0;
      int n = length(root);
   //cout<<n;
      int el=n-k+1;
        Inorder(root,count,el,data);
        return data;
    }
};