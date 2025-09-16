// Method:
// - append() is a method called on an existing object that modifies it.
// - Concatenation with + creates a new string and does not modify the original strings.
// Return Type:
// - append() modifies the original string and returns a reference to it.
// - Concatenation with + returns a new string.

// - append() is generally more efficient than concatenation with +, especially in a loop.
// - append() is preferred when building a string incrementally, as it avoids unnecessary copies.
// using s+= will give TLE in large test cases
// - append() is more efficient for large strings or when building a string in a loop.
// this code only works if we use append() method to build the string


class Codec {
public:
    void Preorder(TreeNode* root, string& ans) {
        if (!root) {
            ans.append("N,");
            return;
        }
        ans.append(to_string(root->val));
        ans.append(",");
        Preorder(root->left, ans);
        Preorder(root->right, ans);
    }

    TreeNode* InorderDeserialize(const vector<string>& arr, int& i) {
        if (arr[i] == "N") {
            ++i;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(arr[i]));
        ++i;
        root->left = InorderDeserialize(arr, i);
        root->right = InorderDeserialize(arr, i);
        return root;
    }

    string serialize(TreeNode* root) {
        string ans;
        Preorder(root, ans);
        if (!ans.empty() && ans.back() == ',') {
            ans.pop_back();
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        vector<string> arr;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ',')) {
            arr.push_back(item);
        }
        int i = 0;
        return InorderDeserialize(arr, i);
    }
};
