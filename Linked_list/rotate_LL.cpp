
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

//optimal approach : TC : O(n) SC : O(1)
class Solution {
public:
ListNode * lastnodefinder(ListNode* head,int length){
    int count=1;
    ListNode* temp=head;

    while(temp!=nullptr){
        if(count==length){
            return temp;
        }
        count++;
        temp=temp->next;
    }
    return nullptr;
}
    ListNode* rotateRight(ListNode* head, int k) {
    if(head==nullptr || k==0){
        return head;
    }
        ListNode* temp=head;
        ListNode*tail;
        int size=0;
        while(temp!=nullptr){
        size++;
        tail=temp;
        temp=temp->next;
        }
        if(k%size==0){
            return head;
        }
        k=k%size;
        tail->next=head;
        ListNode * lastnode=lastnodefinder(head,size-k);
        head=lastnode->next;
        lastnode->next=nullptr;
        return head;

    }
};
