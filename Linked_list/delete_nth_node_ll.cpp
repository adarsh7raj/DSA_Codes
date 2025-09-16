// O(2n):

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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode*temp1=head;
            ListNode*temp2=head;
            ListNode*prev=nullptr;
            int count=0;
            
            while(temp1!=nullptr){
                temp1=temp1->next;
                count++;
            }
            if(count==1){
                return temp1;
            }
            if(count==n){
                return head->next;
            }
            int i=0;
            while(i!=count-n){
                prev=temp2;
          temp2=temp2->next;
          i++;
            }
        
            prev->next=temp2->next;
               delete temp2;
               return head;
        }
    };

    // in O(n) time :

    class Solution {
        public:
            ListNode* removeNthFromEnd(ListNode* head, int n) {
                // Dummy node to handle edge cases easily
                ListNode* dummy = new ListNode(0);
                dummy->next = head;
        
                ListNode* fast = dummy;
                ListNode* slow = dummy;
        
                // Move fast pointer n+1 steps ahead
                for (int i = 0; i <= n; ++i) {
                    fast = fast->next;
                }
        
                // Move both pointers until fast reaches the end
                while (fast != nullptr) {
                    fast = fast->next;
                    slow = slow->next;
                }
        
                // Delete the nth node from end
                ListNode* nodeToDelete = slow->next;
                slow->next = slow->next->next;
                delete nodeToDelete; // Free memory
        
                ListNode* result = dummy->next;
                delete dummy; // Clean up dummy node
                return result;
            }
        };
        