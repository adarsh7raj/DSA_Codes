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
        ListNode* middleNode(ListNode* head) {
            ListNode*temp=head;
            int count=0;
         while(temp!=nullptr){
            temp=temp->next;
     count++;
         }
         if(count==1){
            return head;
         }
         int i=1;
         ListNode*current=head;
          while(i<count/2 && current!=nullptr){
            current=current->next;
            i++;
          }
          return current->next;
        }
    };