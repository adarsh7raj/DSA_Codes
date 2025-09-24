

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
    ListNode* oddEvenList(ListNode* head) {
        // brute force 

        // store the odd index nodes in mp1 and even index node in map2
        // and then simply traverse the map1 and them mp2 and connect the nodes ;
        // optimal solution : 
       if (!head || !head->next) return head;

     ListNode* oddHead=head;
     ListNode* evenHead=head->next;
     ListNode*temp1=oddHead;
     ListNode*temp2=evenHead;
       
     while((temp1!=nullptr && temp1->next!=nullptr) && (temp2!=nullptr && temp2->next!=nullptr)){
 
temp1->next=temp1->next->next;
temp1=temp1->next;
temp2->next=temp2->next->next;
temp2=temp2->next;
     }
     temp1->next=evenHead;
     return oddHead;
        }
    };