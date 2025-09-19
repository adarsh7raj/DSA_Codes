// brute force : TC : O(n) ans SC: O(n):

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
        bool isPalindrome(ListNode* head) {
         
        ListNode* cloneHead = new ListNode(head->val);
        ListNode*  dummy=cloneHead;
        ListNode* original_head = head;
    
        while (original_head !=nullptr && original_head->next!=nullptr) {
            cloneHead->next = new ListNode(original_head->next->val);
            cloneHead=cloneHead->next;
            original_head=original_head->next;
        }
       
         
    
            ListNode*temp=head;
            ListNode*prev=nullptr;
            ListNode*current=dummy;
            ListNode*next=nullptr;
            while(current!=nullptr){
                next=current->next;
                current->next=prev;
                prev=current;
                current=next;
            }
            while(temp!=nullptr ){
                if(temp->val!=prev->val){
                    return false;
                }
                temp=temp->next;
                prev=prev->next;
            }
            return true;
    
        }
    
    };

    //optimal solution : SC : O(n) TC : O(1)
    class Solution {
        public:
            bool isPalindrome(ListNode* head) {
                if (!head || !head->next) return true;
        
                // Step 1: Find the middle
                ListNode* slow = head;
                ListNode* fast = head;
                while (fast && fast->next) {
                    slow = slow->next;
                    fast = fast->next->next;
                }
        
                // Step 2: Reverse second half
                ListNode* secondHalf = reverseList(slow);
                ListNode* firstHalf = head;
                ListNode* secondHalfCopy = secondHalf; // Optional: to restore later
        
                // Step 3: Compare both halves
                while (secondHalf) {
                    if (firstHalf->val != secondHalf->val) {
                        return false;
                    }
                    firstHalf = firstHalf->next;
                    secondHalf = secondHalf->next;
                }
        
                // Optional Step 4: Restore the original list
                // reverseList(secondHalfCopy);
        
                return true;
            }
        
        private:
            ListNode* reverseList(ListNode* head) {
                ListNode* prev = nullptr;
                while (head) {
                    ListNode* next = head->next;
                    head->next = prev;
                    prev = head;
                    head = next;
                }
                return prev;
            }
        };
        
