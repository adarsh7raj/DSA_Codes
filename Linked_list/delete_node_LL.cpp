//We’re asked to delete a given node in a singly-linked list.
// Constraints:

// We are not given the head of the list.

// We are guaranteed that the node to delete is not the tail.

// So we can’t do the usual prev->next = node->next trick, since we don’t know the prev.


class Solution {
public:
    void deleteNode(ListNode* node) {
        // Step 1: Copy the value of the next node
        node->val = node->next->val;

        // Step 2: Store the next node temporarily
        ListNode* temp = node->next;

        // Step 3: Skip over the next node
        node->next = node->next->next;

        // Step 4: Free memory of the skipped node
        delete temp;
    }
};
