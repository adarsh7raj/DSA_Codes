#include <iostream>
#define MAX 5
using namespace std;

class Queue {
    int arr[MAX];
    int front, rear, count;

public:
    Queue() {
        front = 0;
        rear = 0;
        count = 0;
    }

    void push(int x) {
        if (count == MAX) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[rear] = x;
        rear = (rear + 1) % MAX;
        count++;
    }

    void pop() {
        if (count == 0) {
            cout << "Queue Underflow\n";
            return;
        }
        front = (front + 1) % MAX;
        count--;
    }

    int top() {
        if (count == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }
};

int main() {
    Queue q;
    q.push(2);
    q.push(3);
    q.pop();
    q.pop();
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);  // Should work
    q.push(8);  // Should give overflow

    while (!q.isEmpty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
