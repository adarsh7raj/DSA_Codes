
// TC :O(n) , SC :O(h) where n is the number of nodes in the binary tree and h is the height of the binary tree

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr){
            return true;
        }
        if(p==nullptr && q!=nullptr){
            return false;
        }
        if(q==nullptr && p!=nullptr){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
       bool leftN= isSameTree(p->left,q->left);
       bool rightN=false;
       if(leftN){
           rightN= isSameTree(p->right,q->right);
       }
      
       if(leftN && rightN){
        return true;
       }
       if(leftN==true && rightN==false){
        return false;
       }
       if(rightN==true && leftN==false){
        return false;
       }
       return false;
    }
};

// more clean syntax and code :

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
