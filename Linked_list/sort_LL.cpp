

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
ListNode* mergeTwoLists(ListNode *list1,ListNode *list2) {
        if(list1 == NULL) {
            return list2;
        }

        if(list2 == NULL) {
            return list1;
        }

         ListNode* result;
        if(list1->val < list2->val) {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        } else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }

        return result;
    }
ListNode* findMid(ListNode* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

// main function
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
             return head;
        }
           
            ListNode* mid=findMid(head);
            ListNode* leftHead=head;
            ListNode* rightHead=mid->next;
            mid->next=nullptr;
            // solve for smaller linked list(find the sorted linked list for the half part of the linked list)
            leftHead=sortList(leftHead); // this will return the sorted linked list head for the left part
            rightHead=sortList(rightHead); // this will return the sorted linked list head for the right part
            // merge the two sorted linked list and return the head of the merged linked list
           return mergeTwoLists(leftHead,rightHead);
        }
    
};