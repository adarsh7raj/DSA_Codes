
// TC -> O(N log k)
// SC -> O(k)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto node : lists){
         while(node !=nullptr){
             pq.push(node->val);
             node=node->next;
         }
        }
        
        ListNode*root=nullptr;
        ListNode*temp;
        if(!pq.empty()){
             temp=new ListNode(pq.top());
            root=temp;
             pq.pop();
        }
       
        
       
        
        while(!pq.empty()){
        ListNode* curr=new  ListNode(pq.top());
        temp->next=curr;
        temp=temp->next;
        pq.pop();

        }
        return root;
    }
};