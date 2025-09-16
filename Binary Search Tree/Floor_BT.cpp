

class Solution {

  public:
  int  predecessor=INT_MIN;
   void InorderTreeVal(Node* root,int key){
     if(root==nullptr){
            return ;
        }
        
            if(root->data<=key){
           predecessor=max(predecessor,root->data);
            }
           
        
       InorderTreeVal(root->left,key);
       
       InorderTreeVal(root->right,key);
    }
    int floor(Node* root, int x) {
        // Code here
        if(predecessor==INT_MIN){
            predecessor=-1;
        }
        InorderTreeVal(root,x);
        return predecessor;
        
    }
};


// optimal solution 
// TC : O(h) where h is the height of the binary tree
// SC: O(1) no extra space used


 int floor(Node * ,int x){
    int floor=-1;
    while(root!=nullptr){
        if(root->data==x){
            return root->data; // Found exact match
        }
        else if(root->data < x){
            floor = root->data; // Update floor
            root = root->right; // Move to right subtree
        }
        else {
            root = root->left; // Move to left subtree
        }
    }
 }