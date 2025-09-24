// You are given the head_ref of a doubly Linked List and a Key.
//  Your task is to delete all occurrences of the given key if it is present and return the new DLL.
// TC : O(n) , SC : O(1)
class Solution {
public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* head = *head_ref;
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->data == x) {
                Node* toDelete = curr;

                // If node is head
                if (curr == *head_ref) {
                    *head_ref = curr->next;   // Move head
                    if (*head_ref != nullptr)
                        (*head_ref)->prev = nullptr;
                } 
                else {
                    if (curr->prev != nullptr)
                        curr->prev->next = curr->next;
                    if (curr->next != nullptr)
                        curr->next->prev = curr->prev;
                }

                curr = curr->next;  // Move forward
                delete toDelete;    // Free memory
            } 
            else {
                curr = curr->next;
            }
        }
    }
};
