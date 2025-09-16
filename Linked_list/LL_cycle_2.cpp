//brute force approach : O(n) but SC : O(n)

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
        ListNode *detectCycle(ListNode *head) {
            unordered_map <ListNode*,int>mp;
            ListNode* temp=head;
            while(temp!=nullptr){
           if(mp.count(temp)){
            cout<<temp->val;
            return temp;
           }
           mp[temp]=temp->val;
           temp=temp->next;
            }
            return nullptr;
        }
    };

    //optimal solution : O(n)  SC : O(1)


class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if(head==nullptr){
                return nullptr;
            }
            if(head->next==nullptr){
                return nullptr;
            }
            ListNode* slow=head->next;
            ListNode* fast=head->next->next;
            while(slow!=fast){
                if(fast==nullptr || fast->next==nullptr){
                    return nullptr ;
                }
                slow=slow->next;
                fast=fast->next->next;
               
            }
             slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
        }
                
            
         
    };

    // syntactically more better version :  O(n)  and SC O(1)

    class Solution {
        public:
            ListNode *detectCycle(ListNode *head) {
                if (head == nullptr || head->next == nullptr) {
                    return nullptr;
                }
        
                ListNode* slow = head;
                ListNode* fast = head;
        
                while (fast != nullptr && fast->next != nullptr) {
                    slow = slow->next;
                    fast = fast->next->next;
        
                    if (slow == fast) {
                        // Cycle detected
                        slow = head;
                        while (slow != fast) {
                            slow = slow->next;
                            fast = fast->next;
                        }
                        return slow;
                    }
                }
        
                return nullptr; // No cycle
            }
        };
        