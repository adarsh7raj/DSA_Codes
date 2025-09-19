// optimized aproach using our own doubly linked list and hashmap
// intuition we make a dll to store the most recently used at the front and least recently used at the back
// and a hashmap to store the key and the address of the node in the dll


// TC : O(1) for both get and put
// SC : O(capacity) for hashmap and dll

#include <unordered_map>
using namespace std;

// Node of the doubly linked list
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; // dummy head
    Node* tail; // dummy tail

    // Remove node from linked list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert node right after head
    void insertNode(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

public:
// Constructor to initialize the LRU cache with given capacity
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1); // dummy head
        tail = new Node(-1, -1); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = cache[key];
        deleteNode(node);      
        insertNode(node); // move to front
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* existing = cache[key];
            existing->value = value;
            deleteNode(existing);
            insertNode(existing); // move to front
        } else {
            if ((int)cache.size() == capacity) {
                // Remove least recently used node (before tail)
                Node* lru = tail->prev;
                cache.erase(lru->key);
                deleteNode(lru);
                delete lru;
            }

            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertNode(newNode);
        }
    }
//destructor to free memory
    ~LRUCache() {
        // Clean up memory
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};







//Approach-1 (Brute Force)

// total complexity for get():

// Worst case = Loop O(n) + Erase O(n) + Push_back O(1)

// ✅ Overall = O(n + n + 1) = O(n)

// Why not O(n²)?

// Because these operations are sequential, not nested.

// You don’t run an O(n) erase for every element in the loop.

// You loop until you find the element, and erase happens once per get() call, not n times.

// So get() is O(n), not O(n²).

// Similarly for put():

// Loop to find key: O(n)

// Erase + Push_back: O(n) in worst case

// ✅ Overall: O(n)
// push the most recently used at the back and least recently used at the front
// when we reach capacity we pop the front element
class LRUCache {
public:
    
    vector<pair<int, int>> cache;
    int n;
    
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        
        for(int i = 0; i<cache.size(); i++) {
            
            if(cache[i].first == key) {
                int val = cache[i].second;
                
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp); // it is now most recently used so push it at the back
                
                return val;
            }
            
        }
        
        return -1;
        
    }
    
    void put(int key, int value) {
        
        for(int i = 0; i<cache.size(); i++) {
            
            if(cache[i].first == key) {
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }
        
        if(cache.size() == n) {
            cache.erase(cache.begin()); // remove least recently used (front element)
            cache.push_back({key, value}); // insert new element at the back
        } else {
            cache.push_back({key, value});
        }
        
    }
};


//Approach-2 (Optimal)
// TC : O(1) for both get and put
// SC : O(capacity) for hashmap and dll
class LRUCache {
public:
    list<int> dll; //it contains the key
    unordered_map<int, pair<list<int>::iterator, int>> cache; //key->(list_node, value)
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    void makeMostRecentlyUsed(int key) {
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }
    
    int get(int key) {
        if(!cache.count(key))
            return -1;
        
        makeMostRecentlyUsed(key);
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            cache[key].second = value;
            makeMostRecentlyUsed(key);
        } else {
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            capacity--;
        }
        
        if(capacity < 0) {
            cache.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
    }
};




