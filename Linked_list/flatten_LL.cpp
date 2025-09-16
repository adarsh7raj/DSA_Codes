/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */


// brute force apporach : O(KN) K= total nodes in row N=total number of child of one node.

Node* Merge_lists(Node* A, Node* B) {
    Node* temp = new Node(0);  // Dummy node
    Node* res = temp;

    while (A != nullptr && B != nullptr) {
        if (A->data < B->data) {
            temp->child = A;
            A = A->child;
        } else {
            temp->child = B;
            B = B->child;
        }
        temp = temp->child;
    }

    // Attach remaining nodes
    if (A != nullptr) temp->child = A;
    if (B != nullptr) temp->child = B;

    return res->child;  // Return the merged list
}

Node* flattenLinkedList(Node* head) {
    if (!head || !head->next) return head;

    Node* merged = head;
    Node* current = head->next;

    while (current != nullptr) {
        merged = Merge_lists(merged, current);
        current = current->next;
    }

    return merged;
}

//optimal solution :
// Merge two sorted lists using child pointer
Node* Merge_lists(Node* A, Node* B) {
    Node* temp = new Node(0);  // Dummy node
    Node* res = temp;

    while (A != nullptr && B != nullptr) {
        if (A->data < B->data) {
            temp->child = A;
            A = A->child;
        } else {
            temp->child = B;
            B = B->child;
        }
        temp = temp->child;
    }

    // Attach remaining nodes
    if (A != nullptr) temp->child = A;
    if (B != nullptr) temp->child = B;

    return res->child;  // Return the merged list
}

// Recursively flatten the list
Node* flatten(Node* root) {
    if (root == nullptr || root->next == nullptr) {
        return root;
    }

    // Recursively flatten next
    root->next = flatten(root->next);

    // Merge current list with flattened next
    root = Merge_lists(root, root->next);

    return root;
}

// Entry point to flatten the multilevel linked list
Node* flattenLinkedList(Node* head) {
    return flatten(head);
}
