


class Solution {
public:
 vector<vector<int>> levelOrder(Node* root) {
      
        queue<Node*>q;
        vector<vector<int>>ans;
          if(root==nullptr){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>result;
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                if(i==size-1){
                    temp->next=nullptr;
                }
                else{
                      Node*temp1=q.front();
                      temp->next=temp1;
                }
               
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

    Node* connect(Node* root) {
    levelOrder(root);
    return root;
    }
};