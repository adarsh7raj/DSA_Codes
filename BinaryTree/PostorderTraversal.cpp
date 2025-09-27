

// TC : O(n)
// SC : O(n) (not considering the output vector) because we are using recursion
class Solution {
public:
 void PostorderTreeTraversal(TreeNode* root,vector<int> & ans){
    if(root==nullptr){
        return;
    }
    PostorderTreeTraversal(root->left,ans);
    PostorderTreeTraversal(root->right,ans);
    ans.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        PostorderTreeTraversal(root,ans);
        return ans;
    }
};

//iteraative approach using two stack  TC: O(n) SC: O(2n) 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();

            st2.push(node);

            if (node->left != nullptr) {
                st1.push(node->left);
            }
            if (node->right != nullptr) {
                st1.push(node->right);
            }
        }

        while (!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};

// iterative approach using one stack TC: O(n) SC: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;

        while (!st.empty() || current != nullptr) {
            if (current != nullptr) {
                st.push(current);
                current = current->left;   // go left as much as possible
            } else {
                TreeNode* peekNode = st.top();
                // if right child exists and is not processed yet
                if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                    current = peekNode->right;
                } else {
                    ans.push_back(peekNode->val);
                    lastVisited = peekNode;
                    st.pop();
                }
            }
        }

        return ans;
    }
};


// another approach just doing this : Root|Right|Left and then reversing the ans vector TC: O(n) SC: O(n)



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
        if (curr->left)  st.push(curr->left);
        if (curr->right) st.push(curr->right);
        
    }
    reverse(ans.begin(),ans.end());
    return ans; 
}