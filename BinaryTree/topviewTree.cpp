


class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        if(root==nullptr){
            return ans;
        }
        q.push({root,0});
        while(!q.empty()){
            Node* temp=q.front().first;
            int x=q.front().second;
// Check if the current horizontal distance is not already in the map.
            // This ensures we only take the first node encountered at each horizontal distance.

            if(!mp.count(x)){
                mp[x]=temp->data;
            }
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