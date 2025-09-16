#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
    Node *frontNode, *rearNode;

public:
    Queue() {
        frontNode = rearNode = nullptr;
    }

    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = nullptr;

        if (rearNode == nullptr) {
            frontNode = rearNode = temp;
        } else {
            rearNode->next = temp;
            rearNode = temp;
        }
    }

    void pop() {
        if (frontNode == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;

        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp;
    }

    int front() {
        if (frontNode == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return frontNode->data;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }
};

int main() {
    Queue q;
    q.push(5);
    q.push(15);
    q.pop();
    cout << "Front: " << q.front() << endl; // Should print 15
}
