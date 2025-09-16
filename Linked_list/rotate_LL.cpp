
// Tc : O(k*n):
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp1=head;
        int count =0;
     while(temp1!=nullptr){
temp1=temp1->next;
count++;
     }
       ListNode* temp=head;
       ListNode* new_head=head;
       if(head==nullptr || head->next==nullptr){
        return head;
       }
       if(count<k){
  if(k%count==0){
        return head;
       }
       else{
        int i=k%count;
        while(i>0){
             while(temp->next->next!=nullptr){
            temp=temp->next;
        }
    ListNode* last=temp->next;
        temp->next=nullptr;
        last->next=new_head;
        new_head=last;
        temp=new_head;
        i--;
        }
    return new_head;
       }
       }
     
        while(k>0){
             while(temp->next->next!=nullptr){
            temp=temp->next;
        }
    ListNode* last=temp->next;
        temp->next=nullptr;
        last->next=new_head;
        new_head=last;
        temp=new_head;
        k--;
        }
    return new_head;
    }
};

//optimal approach : O(n+n-n%k):
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length and tail
        ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // Step 2: Make the list circular
        tail->next = head;

        // Step 3: Find new tail and head
        k = k % n;
        int stepsToNewTail = n - k;
        ListNode* newTail = head;
        while (--stepsToNewTail) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        // Step 4: Break the circle
        newTail->next = nullptr;

        return newHead;
    }
};
