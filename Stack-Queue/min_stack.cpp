//brute force : O(n):

class MinStack {
    stack<int>st; 
public:
    MinStack() {
    
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        if(!st.empty()){
        st.pop();
        }
  
    }
    
    int top() {
        if(!st.empty()){
   return  st.top();
        }
    return -1;
    }
    int minimum=INT_MAX;
    int getMin() {
         int minimum=INT_MAX;
        stack<int>st1;
        st1=st;
        while(!st1.empty()){
            minimum=min(minimum,st1.top());
            st1.pop();
        }
        return minimum;
    }
};



//better approach : TC:O(1) and SC: O(2n):

class MinStack {
    stack<pair<int,int>>st; 
public:
    MinStack() {
    
    }
    
    void push(int val) {
        if(st.empty()){
           st.push({val,val});
        }
        else{
             st.push({val,min(st.top().second,val)});
        }
      
    }
    
    void pop() {
        if(!st.empty()){
        st.pop();
        }
  
    }
    
    int top() {
        if(!st.empty()){
   return  st.top().first;
        }
    return -1;
    }

    int getMin() {
         
     
        return st.top().second;
    }
};
// better approach : TC:O(1) SC:O(2n):

#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

// optimal  solution : 



#include <stack>
using namespace std;

class MinStack {
private:
    stack<long long> st;
    long long minVal;

public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minVal = val;
        } else if (val >= minVal) {
            st.push(val);
        } else {
            // Push encoded value
            st.push(2LL * val - minVal);
            minVal = val;
        }
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() >= minVal) {
            st.pop();
        } else {
            // Restore previous minVal
            minVal = 2 * minVal - st.top();
            st.pop();
        }
    }

    int top() {
        if (st.empty()) return -1;

        if (st.top() >= minVal) {
            return st.top();
        } else {
            // Encoded value means actual top is minVal
            return minVal;
        }
    }

    int getMin() {
        return minVal;
    }
};
