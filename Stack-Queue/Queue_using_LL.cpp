class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
int sz;
Node* front_node;
Node* rear_node;
  public:
    myQueue() {
        // Initialize your data members
        front_node=nullptr;
        rear_node=nullptr;
        sz=0;
        
        
    }

    bool isEmpty() {
        // check if the queue is empty
        if(sz==0){
            return true;
        }
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        if(sz==0){
            rear_node=front_node=new Node(x);
        }
        else{
            Node* temp=new Node(x);
            rear_node->next=temp;
            rear_node=temp;
        }
        sz++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(sz==0){
            
            return ;
        }
        Node * temp=front_node;
        front_node=front_node->next;
        delete temp;
        sz--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(sz==0){
            return -1;
        }
        return front_node->data;
    }

    int size() {
        // Returns the current size of the queue.
        return sz;
    }
};
