

// brute force solution
// TC : O(n) where n is the number of nodes in the binary tree



class Solution {
  public:
  int predecessor=INT_MIN;
  int successor=INT_MAX;
   void InorderTreeVal(Node* root,int key){
     if(root==nullptr){
            return ;
        }
        if(root->data!=key){
            if(root->data>key){
                successor=min(successor,root->data);
            }
            else{
                predecessor=max(predecessor,root->data);
            }
        }
       InorderTreeVal(root->left,key);
       
       InorderTreeVal(root->right,key);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*>ans;
        
      InorderTreeVal(root,key);
      if(predecessor==INT_MIN){
          predecessor=-1;
      }
      if(successor==INT_MAX){
         successor=-1;
      }
      Node* pred=new Node(predecessor);
      Node* succ=new Node(successor);
      ans.push_back(pred);
      ans.push_back(succ);
       return ans;
        
    }
};



// optimal solution // TC : O(n) where n is the number of nodes in the binary tree
// SC: O(1) no extra space used

 pair<Node*, Node*> findPreSuc(Node* root, int key) {
        Node* curr = root;
        Node* predecessor = nullptr;
        Node* successor = nullptr;

        // Step 1: Find the key node
        while (curr && curr->data != key) {
            if (key < curr->data) {
                successor = curr;  // Potential successor
                curr = curr->left;
            } else {
                predecessor = curr;  // Potential predecessor
                curr = curr->right;
            }
        }

        // If key is not found
        if (!curr) {
            return {predecessor, successor};
        }

        // Step 2: Find the max value in the left subtree (predecessor)
        if (curr->left) {
            Node* temp = curr->left;
            while (temp->right) {
                temp = temp->right;
            }
            predecessor = temp;
        }

        // Step 3: Find the min value in the right subtree (successor)
        if (curr->right) {
            Node* temp = curr->right;
            while (temp->left) {
                temp = temp->left;
            }
            successor = temp;
        }

        return {predecessor, successor};
    }


    // optimal solution 

    /* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

  class Solution {
public:
    // Function to find predecessor and successor
    void findPredSucc(Node* root, Node*& pre, Node*& suc, int key) {
      while(root!=nullptr){
           if (root->data == key) {
            // Find predecessor (max in left subtree)
            if (root->left) {
                Node* temp = root->left;
                while (temp->right) {
                    temp = temp->right;
                }
                pre = temp;
            }
            // Find successor (min in right subtree)
            if (root->right) {
                Node* temp = root->right;
                while (temp->left) {
                    temp = temp->left;
                }
                suc = temp;
            }
            break;
        } else if (root->data > key) {
            suc = root; // Possible successor
            root=root->left;
        } else {
            pre = root; // Possible predecessor
            root=root->right;
        }
      }

       
    }

 
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
       
        Node* pre = nullptr;
    Node* suc = nullptr;
    findPredSucc(root, pre, suc, key);
    return {pre, suc};
    }
};