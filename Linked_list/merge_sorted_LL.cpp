// using new node O(n1+n2):

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            // ListNode dummy;   struct itself is the dummy (node) dummy is storing the node itself
            // ListNode* tail = &dummy;
     ListNode* dummy=new ListNode(0,nullptr);  //here dummy is storing the address instead of actual node 
     ListNode*tail=dummy;
            while (list1 && list2) {
                if (list1->val <= list2->val) {
                    tail->next = list1;
                    list1 = list1->next;
                } else {
                    tail->next = list2;
                    list2 = list2->next;
                }
                tail = tail->next;
            }
    
            // Connect the remaining part also to check to which node is to connect list1 and list2:
            if (list1) tail->next = list1;
            if (list2) tail->next = list2;
    
            return dummy->next;
        }
    };
    
    // without using any extra space :

    class Solution {
        public:
            ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
              
              if(list1==nullptr){
        return list2;
              }
              if(list2==nullptr){
                return list1;
              }
              if(list1->val>list2->val){
                swap(list1,list2);
              }
              ListNode*result=list1;
        while(list1!=nullptr && list2!=nullptr){
        ListNode*temp=nullptr;
        while(list1!=nullptr && list1->val<=list2->val){
            temp=list1;
            list1=list1->next;
        }
        temp->next=list2;
        swap(list1,list2);
        
        }
         return result;       
            }
        };
        

        // using recursion :

        struct Node* mergeTwoLists(Node *list1,Node *list2) {
        if(list1 == NULL) {
            return list2;
        }

        if(list2 == NULL) {
            return list1;
        }

        struct Node* result;
        if(list1->data < list2->data) {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        } else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }

        return result;
    }