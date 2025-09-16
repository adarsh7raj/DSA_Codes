

// You are given the head of a singly linked list.
// Return the middle node of the linked list.

// If there are two middle nodes (even length), return the second middle node.

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

//  ✅ Time & Space Complexity

// TC: O(N + N/2) ≈ O(N)

// SC: O(1) (no extra space)
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



//     Optimal Solution (One-Pass with Two Pointers)

// Instead of counting length, use two pointers:

// slow moves 1 step at a time.

// fast moves 2 steps at a time.

// When fast reaches the end, slow will be at the middle.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // slow is at middle
    }
};


// ✅ This is one-pass, cleaner, and works for both even/odd lengths automatically.