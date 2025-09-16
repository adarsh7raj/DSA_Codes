
// TC : O(n) SC : O(n) (not considering the output vector)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      
        queue<TreeNode*>q;
        vector<vector<int>>ans;
          if(root==nullptr){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>result;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=nullptr){
                    q.push(temp->left);

                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }
                result.push_back(temp->val);
            }
            ans.push_back(result);
        }
        return ans;
    }
};