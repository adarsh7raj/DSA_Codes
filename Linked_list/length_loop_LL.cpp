
// brute force : TC : O(n) , SC : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        map<Node*,int>mp;
            Node* temp=head;
            while(temp!=nullptr){
                if(mp.count(temp)){
                    int count=1;
                    Node* t=temp->next;
                    while(t!=temp){
                        count++;
                        t=t->next;
                    }
                    return count;
                }
                mp[temp]=temp->data;
                temp=temp->next;
            }
            return 0;
    }
};
/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// optimal solution : TC : O(n) , SC : O(1)
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow=head;
            Node* fast=head;
            while(fast!=nullptr && fast->next!=nullptr){
               
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast){
                    break;
                }
               
            }
             if(fast==nullptr || fast->next==nullptr){
                    return 0 ;
                }
           
              int count=1;
              while(slow->next!=fast){
                  count++;
                  slow=slow->next;
              }
                return count;
    }
};