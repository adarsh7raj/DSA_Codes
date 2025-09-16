#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1;

public:
    MyStack() {}

    void push(int x) {
        q1.push(x);
        int size = q1.size();
       for(int i=1;i<q1.size();i++) {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
