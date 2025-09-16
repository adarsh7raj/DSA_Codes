// brute force approach : O(nlogn)


class MedianFinder {
    public:
    vector<int> nums;
        MedianFinder() {
          
        }
        void addNum(int num) {
            nums.push_back(num);
            sort(nums.begin(),nums.end());
        }
        
        double findMedian() {
            if(nums.size()%2){
              return  nums[nums.size()/2];
            }
            else{
                double ans=(nums[nums.size()/2]+nums[nums.size()/2-1])/2.0;
                return ans;
            }
        }
    };
    
    /**
 
     */




//optimal solution : O(logN):

// ** important to note :

// That strange number

// 18446744073709551615


// is actually size_t underflow (wrap-around), and that’s why your median ended up wrong in the last step.

// Why this happens

// In your balancing check:

// if ((maxHeap.size() - minHeap.size()) > 1) {
//     cout << maxHeap.size() - minHeap.size();
//     ...
// }


// ⚠️ maxHeap.size() and minHeap.size() both return size_t, which is an unsigned integer.

// So when minHeap.size() > maxHeap.size(), the subtraction

// maxHeap.size() - minHeap.size()


// becomes negative, but since size_t is unsigned, it wraps around to a huge positive number.

// Example from your case at Step 5 (after inserting 3):

// maxHeap.size() = 1

// minHeap.size() = 2

// So mathematically: 1 - 2 = -1.
// But in size_t, that becomes
// 18446744073709551615 (on a 64-bit system).

// That’s exactly what you saw printed.

// Consequences

// The condition (maxHeap.size() - minHeap.size()) > 1 is true (because 18446744073709551615 > 1).

// The code incorrectly moves an element from maxHeap → minHeap.

// Heaps become unbalanced, and your median comes out wrong (1 instead of 2).


class MedianFinder {
    public:
        priority_queue<int> maxHeap; // lower half
        priority_queue<int, vector<int>, greater<int>> minHeap; // upper half
    
        MedianFinder() {}
    
        void addNum(int num) {
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
    
            // Balance the heaps
            // if i do not type cast the maxheap and minHeap to integer this will give wrong answer
            // because size() returns size_t which is unsigned integer
            // so when minHeap.size() > maxHeap.size() then the subtraction will be negative
            // but since size_t is unsigned it will wrap around to a huge positive number
            // so the condition will be true and the code will incorrectly move an element from maxHeap to minHeap
            // heaps become unbalanced and the median comes out wrong
            if ((int)maxHeap.size() - (int)minHeap.size() > 1) {
                cout<<maxHeap.size()-minHeap.size();
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    
        double findMedian() {
            if (maxHeap.size() == minHeap.size()) {
                return (maxHeap.top() + minHeap.top()) / 2.0;
            } else {
                return maxHeap.top();
            }
        }
    };
    