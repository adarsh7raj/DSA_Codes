// brute force approach :  O(n) in worst case O(nlogn)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode* temp=head;
            map<ListNode*,int>mp;
            while(temp!=nullptr){
     if(mp.count(temp)){
        return true;
     }
    mp[temp]=temp->val;
    temp=temp->next;
            }
            return false;
        }
    };

    // floyd warshall algo : TC : O(n) , SC : O(1):

    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode* slow=head;
            ListNode*fast=head;
            if(head==nullptr || head->next==nullptr){
                return false;
            }
           
            if(head->next==head){
                return true;
            }
            while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
           if(slow==fast){
            
             return true;
        }
            }
         return false;
            }
          
        
    };