// uisng two stacks to implement a queue
//TC : O(1) amortized for push, O(1) amortized for pop and peek . (it can be O(n) in worst case when
// we have to transfer elements from s1 to s2)
//SC : O(n)



#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2;
    int top_element=-1;

public:
    void push(int x) {
        if(s1.empty()){
            top_element=x;
        }
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        if (s2.empty()) {
            return top_element;
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};



// using single stack and recursion
// TC : O(n) for pop and peek , O(1) for push
// SC : O(n) for recursion stack

#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> st;

public:
    // Enqueue
    void enqueue(int x) {
        st.push(x);
    }

    // Dequeue
    int dequeue() {
        if (st.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (st.size() == 1) {
            int front = st.top();
            st.pop();
            return front;
        }

        int topElement = st.top();
        st.pop();

        int front = dequeue();

        st.push(topElement);
        return front;
    }

    // Peek (Front element)
    int peek() {
        if (st.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (st.size() == 1) {
            return st.top(); // do NOT pop
        }

        int topElement = st.top();
        st.pop();

        int front = peek();

        st.push(topElement);
        return front;
    }

    bool isEmpty() {
        return st.empty();
    }
};
