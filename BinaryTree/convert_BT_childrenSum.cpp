// C++ code to convert a binary tree to a tree where each node's value is the sum of its children's values
// And you can only increament the value of any node by +1
//TC : O(n) because we are traversing all nodes once
//SC: O(h) // where h is the height of the tree because we are using recursion stack
void changeTree(BinaryTreeNode < int > * root) {
    if(root==NULL)
    return;
    int child=0;
    
    if(root->left)
    child+=root->left->data;
    if(root->right)
    child+=root->right->data;

    //we make sure that while going down the child has no shortage
    // what if root is greater than child
    if(child < root->data)
    {
        if(root->left)
        {
            root->left->data=root->data;
        }
        if(root->right)
        {
            root->right->data=root->data;
        }
    }

    changeTree(root->left);
    changeTree(root->right);

    //while going back up
    int tot=0;
    if(root->left)
    tot+=root->left->data;
    if(root->right)
    tot+=root->right->data;
    // now when we come back the sum of childen's will always be greater than or equal to root's value
    // so we can set the root's value to the sum of its children's values
    if(root->left || root->right)
    root->data=tot;
}

