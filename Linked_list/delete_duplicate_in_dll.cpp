// Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the
// linked list.

// TC : O(n) , SC : O(1)
class Solution {
  public:
    Node *removeDuplicates(struct Node *head) {
        if (!head) return head;

        Node* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            if (temp->data == temp->next->data) {
                Node* nodeToDelete = temp->next;

                temp->next = nodeToDelete->next;
                if (temp->next != nullptr) {
                    temp->next->prev = temp;  // only if not last node
                }

                delete nodeToDelete;
            } 
            else {
                temp = temp->next;
            }
        }
        return head;
    }
};
