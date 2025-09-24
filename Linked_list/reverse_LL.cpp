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
        ListNode* reverseList(ListNode* head) {
            ListNode*prev=nullptr;
        
            ListNode*current=head;
    
            ListNode*next=nullptr;
            while(current!=nullptr){
                next=current->next;
                current->next=prev;
                prev=current;
                current=next;
    
            }
            
    return prev;
      
        }    
    
    };

    // recursive approach : slightly bad approach
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
ListNode* tail=nullptr;
ListNode* reversed(ListNode* head,int count){
         if(head==nullptr || head->next==nullptr){
            tail=head;
        return head;
    }

    ListNode* node=reversed(head->next,count+1);
    node->next=head;
    head->next=nullptr;
    if(count==1){
        return tail;
    }
    
    return head;
}
    ListNode* reverseList(ListNode* head) {
      return reversed(head,1);
  
    }    

};

// recursive approach optimal :  better approach
ListNode* reversed(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* newHead = reversed(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

ListNode* reverseList(ListNode* head) {
    return reversed(head);
}

// recursive approach : different approach


ListNode* reversed(ListNode* head, int count, ListNode*& tail) {
    if(head == nullptr || head->next == nullptr) {
        tail = head;   // now this modifies the caller's tail too
        return head;
    }

    ListNode* node = reversed(head->next, count+1, tail);
    node->next = head;
    head->next = nullptr;

    if(count == 1) {
        return tail;
    }

    return head;
}

ListNode* reverseList(ListNode* head) {
    ListNode* tail = nullptr;
    return reversed(head, 1, tail);
}
