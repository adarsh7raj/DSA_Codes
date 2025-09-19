// 1. Which push_back syntax is correct?

// You wrote:

// dll.push_back(vector<int>({1,2,5}));


// ✔️ This is correct — it explicitly constructs a vector<int> and pushes it.

// But you can also just write:

// dll.push_back({1, 2, 3});


// This also works because std::list::push_back can take a vector<int> (and {1,2,3} can be implicitly converted into a vector<int>).
// So both are correct — the second one is just shorter and preferred.

// ✅ 2. Why use & in
// vector<int> &firstVec = dll.front();


// dll.front() returns a reference to the first element of the list.

// If you don’t use &, like this:

// vector<int> firstVec = dll.front();


// It makes a copy of the first vector (extra memory + slower).

// If you use &, you get a reference to the actual vector stored inside the list (no copy, direct access).

// So & avoids copying.

// ✅ 3. Difference between dll.front() and dll.begin()

// dll.front() → gives the first element directly (a vector<int>&).

// dll.begin() → returns an iterator pointing to the first element.
// You need to dereference it with * to access the value:

// vector<int> &firstVec1 = dll.front();   // directly
// vector<int> &firstVec2 = *dll.begin(); // via iterator


// Both give the same result.

// ✅ 4. How to get the last element of the list

// You can use dll.back():

// vector<int> &lastVec = dll.back();       last vector<int>
// int lastElement = lastVec.back();        last int inside last vector


// Or via iterators:

// vector<int> &lastVec = *(--dll.end());   end() points past-the-end, so we move back one step



//mp.begin()->first    (*mp.begin()).first they both are same
// we can use mp.front() or mp.back() in case of map also because map is a associative container
// whereas vector,list,deque are sequence containers we can use front() and back() in them


#include <unordered_map>
using namespace std;


class LFUCache {
private:
    int cap;
    int size;
    unordered_map<int, list<vector<int>>::iterator> mp; //key -> address of list of vector{key, value, freq} it is actually the address of the individual nodes of the list(dll)
    map<int, list<vector<int>>> freq; //freq -> list of vector{key, value, freq} it is actually the dll
    
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    void makeMostFrequentlyUsed(int key) {
        auto &vec = *(mp[key]);
        
        int value = vec[1];
        
        int f     = vec[2];
        // we erasing the node from the current frequency list
        freq[f].erase(mp[key]);
        
        if(freq[f].empty())
        // if the list is empty we remove that frequency from the map
        // we delete the entire entry of that frequency from the map
        // we can use erase function on map it needs an 
            freq.erase(f);
        
        f++;
        
        freq[f].push_front(vector<int>({key, value, f}));
        
        mp[key] = freq[f].begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        // mp[key] is the address of the node in the dll and doing *mp[key] gives the actual node
        auto &vec = (*(mp[key])); // taking it by reference so that actual value changes;
        // each node is type of vector<int> {key, value, freq}
        int value = vec[1];
        
        makeMostFrequentlyUsed(key);
        
        return value;
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        
        if(mp.find(key) != mp.end()) {
            auto &vec = (*(mp[key]));
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }
        else if(size < cap) {
            size++;
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }
        else { //Time to remove LFU or LRU if tie
            
            auto &kaun_sa_list = freq.begin()->second; // freq.begin() gives an iterator to the first element of map[]
            
            int key_delete = (kaun_sa_list.back())[0]; //ordered_map ensures that the begin() will be th eleast frequency
            
            kaun_sa_list.pop_back();
            
            if(kaun_sa_list.empty())
                freq.erase(freq.begin()->first);
            
            freq[1].push_front(vector<int>({key, value, 1}));
            
            mp.erase(key_delete);
            mp[key] = freq[1].begin();
        }
    }
};