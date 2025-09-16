//brute force approach : O(n*m):

class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* tempA = headA;
            while (tempA != nullptr) {
                ListNode* tempB = headB; // reset for each iteration
                while (tempB != nullptr) {
                    if (tempA == tempB) { // compare the actual node pointers
                        return tempA;
                    }
                    tempB = tempB->next;
                }
                tempA = tempA->next;
            }
            return nullptr;
        }
    };

    //optimal solution : O(n+m):

    class Solution {
        public:
            ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
                ListNode* tempA = headA;
                ListNode* tempB=headB;
                int countA=0;
                int countB=0;
                while(tempA!=nullptr){
                    tempA=tempA->next;
                    countA++;
                }
                 
                while(tempB!=nullptr){
                    tempB=tempB->next;
                    countB++;
                }
                  ListNode*temp1=headA;
                  ListNode*temp2=headB;
        if(countA<=countB){
           
          
            int i=0;
        while(i<countB-countA){
        temp2=temp2->next;
        i++;
        }
        }
        else{
            
             int i=0;
             while(i<countA-countB){
                temp1=temp1->next;
                i++;
             }
        }
        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
                return nullptr;
            }
        };
        