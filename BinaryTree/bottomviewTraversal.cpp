



class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        
       queue<pair<Node*,int>>q;
       map<int,int>mp;
       vector<int>ans;
       if(root==nullptr){
           return ans;
       }
       q.push({root,0});
       while(!q.empty()){
          Node*temp=q.front().first;
          int x=q.front().second;
          mp[x]=temp->data;
          q.pop();
          if(temp->left!=nullptr){
              q.push({temp->left,x-1});
          }
          if(temp->right!=nullptr){
              q.push({temp->right,x+1});
          }
       }
       for(auto it:mp){
           ans.push_back(it.second);
       }
       return ans;
    }
};