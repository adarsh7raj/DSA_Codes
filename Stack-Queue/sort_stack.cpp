//recursive appraoch : TC : O(n^2):

// Helper function to insert an element in sorted order
void insertSorted(stack<int>& s, int element) {
    // Base case: stack is empty or top is smaller than element
    if (s.empty() || s.top() <= element) {
        s.push(element);
        return;
    }

    // Otherwise, pop and recurse
    int top = s.top();
    s.pop();
    insertSorted(s, element);

    // Push the popped element back
    s.push(top);
}

// Main recursive function to sort the stack
void sortStack(stack<int>& s) {
    if (!s.empty()) {
        int top = s.top();
        s.pop();
        sortStack(s);
        insertSorted(s, top);
    }
}

// iterative approach : O(n^2)