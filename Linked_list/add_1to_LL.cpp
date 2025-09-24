//You are given a linked list where each element in the list is a node and have an integer data. 
//You need to add 1 to the number formed by concatinating all the list node numbers together and return the 
//head of the modified linked list. 


// TC : O(n) , SC : O(1)
#include<string>

class Solution {
  public:
  Node* reversed(Node* head){
      if(head==nullptr || head->next==nullptr){
          return head;
      }
      Node* newHead=reversed(head->next);
      head->next->next=head;
      head->next=nullptr;
      return newHead;
  }
    Node* addOne(Node* head) {
        bool is_carry=false;
        Node*ReversedHead=reversed(head);
        Node*temp=ReversedHead;
        Node* prev=head;
        while(temp!=nullptr){
           if(temp==ReversedHead){
               if(temp->data==9){
                   temp->data=0;
                   is_carry=true;
               }
               else{
                   temp->data=temp->data+1;
                   is_carry=false;
               }
           }
           else{
               if(is_carry){
                   if(temp->data==9){
                       temp->data=0;
                       is_carry=true;
                   }
                   else{
                       temp->data=temp->data+1;
                       is_carry=false;
                   }
               }
           }
          if(!is_carry){
              break;
          }
           prev=temp;
           temp=temp->next;
        }
        if(is_carry){
            Node* last_node=new Node(1);
            prev->next=last_node;
        }
        Node* originalHead=reversed(ReversedHead);
        return originalHead;
        // return head of list after adding one
    }
};


// recursive approach : TC : O(n) , SC : O(n) due to recursive stack space


// Passing a pointer by value still allows you to modify the object it points to, but not the pointer itself.

// When you pass Node* head (by value), the pointer itself is copied, but both the original and the copy still point to the same Node object in memory.


class Solution {
  public:
 int add(Node*  head){// this works and this also works : int add(Node* &head)
     if(head==nullptr){
         return 1;
     }
     int carry=add(head->next);
     head->data=head->data+carry;
     if(head->data>=10){
         head->data=0;
         carry=1;
     }
     else{
         carry=0;
     }
     return carry;
     
 }
    Node* addOne(Node* head) {
        if(head==nullptr){
            return head;
        }
         Node* dummy=new Node(1);
        dummy->next=head;
     
        int carry=add(head);
          
        if(carry){
            return dummy;
        }
        return head; 
    }
};