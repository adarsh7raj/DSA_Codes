#include <iostream>
using namespace std;
// we have implemented stack using ll in reversed order suppose we habe to push : [10,20,30]
// the linked list will be : 30->20->10->nullptr
class Node {
public:
    int data;
    Node* next;
};

class Stack {
    Node* topNode;
    int size;
public:
    Stack() {
        topNode = nullptr;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = topNode;
        topNode = temp;
    }

    void pop() {
        if (!topNode) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        if (!topNode) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.pop();
    cout << "Top: " << s.top() << endl; // Should print 10
}
