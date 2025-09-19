// Definition of a Doubly Linked List Node
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to create a Doubly Linked List from an array
Node* createDLL(int arr[], int n) {
    if (n == 0) return nullptr;

    // Step 1: Create head
    Node* head = new Node(arr[0]);
    Node* temp = head;

    // Step 2: Insert remaining elements
    for (int i = 1; i < n; i++) {
        Node* new_node = new Node(arr[i]);
        temp->next = new_node;
        new_node->prev = temp;
        temp = temp->next;
    }

    return head;
}
