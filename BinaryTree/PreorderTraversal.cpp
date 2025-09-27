// TC : O(n)
// SC : O(n) (not considering the output vector) because we are using recursion
class Solution {
public:
void PreorderTreeTraversal(TreeNode* root, vector<int> & ans){
    if(root==nullptr){
        return ;
    }
    ans.push_back(root->val);
    PreorderTreeTraversal(root->left,ans);
    PreorderTreeTraversal(root->right,ans);
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
         PreorderTreeTraversal(root,ans);
         return ans;
    }
};


// iterative approach TC: O(n) SC: O(n)

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

vector<int> preorderIterative(Node* root) {
    if (root == nullptr) return;
    vector<int> ans;
    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();

        cout << curr->data << " "; // Visit root
        ans.push_back(curr->data);
        // Push right child first so left is processed first
        if (curr->right) st.push(curr->right);
        if (curr->left)  st.push(curr->left);
    }
    return ans; 
}