// TC : O(2n) SC : O(2n)
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Map from original node to its corresponding copied node
        unordered_map<Node*, Node*> oldToNew;

        // Step 1: Copy nodes and build the new list using next pointers
        Node* orig = head;
        Node* copyHead = new Node(orig->val);
        Node* copy = copyHead;
        oldToNew[orig] = copy;

        orig = orig->next;

        while (orig) {
            Node* newNode = new Node(orig->val);
            copy->next = newNode;
            oldToNew[orig] = newNode;

            copy = copy->next;
            orig = orig->next;
        }

        // Step 2: Assign random pointers using the map
        orig = head;
        copy = copyHead;

        while (orig) {
            copy->random = oldToNew[orig->random]; // works if random is nullptr
            orig = orig->next;
            copy = copy->next;
        }

        return copyHead;
    }
};


//  TC : O(2n) SC: O(2n)

// Definition for a Node.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create new nodes and interleave them with original nodes
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Assign random pointers to copied nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate original and copied lists
        curr = head;
        Node* copiedHead = head->next;
        Node* copyCurr = copiedHead;

        while (curr) {
            curr->next = curr->next->next;
            if (copyCurr->next) {
                copyCurr->next = copyCurr->next->next;
            }
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return copiedHead;
    }
};
