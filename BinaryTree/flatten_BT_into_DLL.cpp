
// This function should return head to the DLL

// This is brute force approach
// TC : O(n)  SC : O(n)
class Solution {
  public:
  void PreorderTraversal(Node * root,vector<Node*>& ans){
    if(root==nullptr){
        return ;
    }
 
    PreorderTraversal(root->left,ans);
       ans.push_back(root);
    PreorderTraversal(root->right,ans);
}
    Node* bToDLL(Node* root) {
        // code here
     
       if(root==nullptr){
            return  nullptr ;
        }
        vector<Node*>ans;
        PreorderTraversal(root,ans);
        int i=0;
       while(i<ans.size()-1){
        Node* temp=ans[i];
       
              temp->right=ans[i+1];
              temp->left=nullptr;
        
        i++;
       
       }
   
        Node* temp=ans[0];
      
        temp->left=nullptr;
        while(temp!=nullptr && temp->right!=nullptr){
            temp->right->left=temp;
            temp=temp->right;
        }
     
        return ans[0];
}
};

// same TC and SC but better code

class Solution {
public:
    // Helper variables to keep track of previous and head nodes
    Node* prev = nullptr;
    Node* head = nullptr;

    // Recursive function to do in-order traversal and conversion
    void bToDLLUtil(Node* root) {
        if (!root) return;

        // Recur for left subtree
        bToDLLUtil(root->left);

        // Now deal with the current node
        if (prev == nullptr) {
            // This is the leftmost node, so it's head of DLL
            head = root;
        } else {
            // Link the previous node with the current node
            prev->right = root;
            root->left = prev;
        }
        prev = root;

        // Recur for right subtree
        bToDLLUtil(root->right);
    }

    // Main function to be called
    Node* bToDLL(Node* root) {
        prev = nullptr;
        head = nullptr;
        bToDLLUtil(root);
        return head;
    }
};


// Morris inorder traversal approach
// TC : O(n)  SC : O(1) (not considering the output DLL)

class Solution {
public:
    Node* bToDLL(Node* root) {
        Node* curr = root;
        Node* head = nullptr;   // Head of the DLL
        Node* prev = nullptr;   // Previous node in DLL

        while (curr) {
            if (!curr->left) {
                // Visit this node
                if (!head) {
                    head = curr;
                }
                if (prev) {
                    prev->right = curr;
                    curr->left = prev;
                }
                prev = curr;
                curr = curr->right;
            } else {
                // Find the inorder predecessor of curr
                Node* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }
                
                if (!pred->right) {
                    // Thread to the current node
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Unthread, visit curr
                    pred->right = nullptr;
                    if (!head) head = curr;
                    if (prev) {
                        prev->right = curr;
                        curr->left = prev;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        return head;