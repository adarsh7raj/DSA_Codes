
/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

// the core idea is to create three different linked list for 0 , 1 and 2
// and then connect them together
class Solution {
  public:
   Node* segregate(Node* head) {
    if (!head || !head->next) return head;

    // Dummy heads for 0s, 1s, and 2s lists
    Node* zeroDummy =new Node(-1);
    
    Node* oneDummy=new Node(-1);
    Node* twoDummy=new Node(-1);
    Node *zero = zeroDummy;
    Node*one = oneDummy; 
    Node*two = twoDummy;

    Node* curr = head;

    // Partition into 3 lists
    while (curr) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
        } else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
        } else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    // Connect the three lists
    zero->next = (oneDummy->next) ? oneDummy->next : twoDummy->next;
    one->next = twoDummy->next;
    two->next = nullptr;

    // New head is the first non-empty list
    return zeroDummy->next ;
}
};