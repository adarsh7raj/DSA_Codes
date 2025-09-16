
// TC : O(n) 

//inside a for loop that runs from i = 0 to i < ans.size() (i.e., height h of the tree). 
//But here’s the important part:

//ans[i] is a vector<int> that contains the values of nodes at the i-th level.

//The sum of all node counts across levels is n.

//So, even though the outer loop runs h times, and reverse() takes O(m) where m is the number 
//of elements at level i, the total amount of work done by all reverse operations combined is still O(n).

// SC: O(n) (not considering the output vector) becuase we are using a queue to store the nodes at each level, and in the worst case, the queue can hold all nodes of the tree at once.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans=levelOrder(root);
        for(int i=0;i<ans.size();i++){
            if(i%2){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};