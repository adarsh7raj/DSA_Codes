


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>mp;
        vector<vector<int>>ans;
        if(root==nullptr){
            return ans;
        }
        q.push({root,{0,0}});
        
        while(!q.empty()){
            // [a,[b,c]]
            TreeNode* temp=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            mp[x][y].insert(temp->val);
            q.pop();
            if(temp->left!=nullptr){
                q.push({temp->left,{x-1,y+1}});
            }
            if(temp->right!=nullptr){
                q.push({temp->right,{x+1,y+1}});
            }
        }
        for(auto p:mp){
            vector<int>result;
            for(auto q:p.second ){
                for(auto it: q.second){
                    result.push_back(it);
                }
            }
            
            ans.push_back(result);
        }
       
        return ans;
    }
};