void changeTree(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    
    int child = 0;

    // Step 1: Calculate children's sum
    if(root->left)  child += root->left->data;
    if(root->right) child += root->right->data;

    // Step 2: Push parent's value down if parent > child
    if(child < root->data) {
        if(root->left)  root->left->data  = root->data;
        if(root->right) root->right->data = root->data;
    }

    // Step 3: Recursive DFS (go down first)
    changeTree(root->left);
    changeTree(root->right);

    // Step 4: While coming back up → set root = sum of children
    int tot = 0;
    if(root->left)  tot += root->left->data;
    if(root->right) tot += root->right->data;

    if(root->left || root->right)  
        root->data = tot;
}
