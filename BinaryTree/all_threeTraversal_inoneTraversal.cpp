
// using recursion

void trav(BinaryTreeNode<int> *root,vector<int> &in, vector<int> &pre, vector<int> &post){
    if(!root) return;
    pre.push_back(root->data);
    
    trav(root->left, in, pre, post);
    in.push_back(root->data);
    trav(root->right, in, pre, post);
    post.push_back(root->data);
}

vector<vector<int>> threeTraversal(BinaryTreeNode<int> *root) {
    vector<int> in, pre, post;
    vector<vector<int>> ans;
    trav(root, in, pre, post);
    ans.push_back(in);
    ans.push_back(pre); 
    ans.push_back(post);
    return ans;
    
}

// second approach using stack

void trav(BinaryTreeNode<int> *root,vector<int> &in, vector<int> &pre, vector<int> &post){
    stack<pair<BinaryTreeNode<int>*, int>> s;
    stack.push({root, 1});
    while(!s.empty()) {
        auto [node, state] = s.top();
        s.pop();
        
        if (!node) continue;
        
        if (state == 1) {
            pre.push_back(node->data);
            state++;
            s.push({node, state});
            if(node->left!=nullptr){
            s.push({node->left, 1});
            } // Push again with state 2
            // Visit left child next
        } 
        else if (state == 2) {
            in.push_back(node->data);
            state++;
            s.push({node, state});
            if(node->right!=nullptr){
                s.push({node->right, 1}); // Visit right child next
            }
        } 
        else {
            post.push_back(node->data);
        }
    }
}
vector<vector<int>> threeTraversal(BinaryTreeNode<int> *root) {
    vector<int> in, pre, post;
    vector<vector<int>> ans;
    trav(root, in, pre, post);
    ans.push_back(in);
    ans.push_back(pre); 
    ans.push_back(post);
    return ans;
}