

lass Solution {
public:
TreeNode* construct(TreeNode*  root,int data){
    if(root==nullptr){
        TreeNode* temp=new TreeNode(data);
        return temp;
    }
    if(root->val>data){
        root->left=construct(root->left,data);
    }
    else{
        root->right=construct(root->right,data);
    }
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=nullptr;
        for(int i=0;i<preorder.size();i++){
            root=construct(root,preorder[i]);
            cout<<root->val;
        }
        
        return root;
    }
};