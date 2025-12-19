// We are given two arrays A and B of size N.
// We need to find the K maximum sums of pairs (A[i] + B[j]) where 0 ≤ i, j < N.
// A = [1, 4, 2]
// B = [3, 5, 1]
// K = 3

// All possible sums = {1+3, 1+5, 1+1, 4+3, 4+5, 4+1, 2+3, 2+5, 2+1}
//                   = {4, 6, 2, 7, 9, 5, 5, 7, 3}
// Top 3 sums = {9, 7, 7}

// brute force approach: TC : O(n^2 + n^2log(n^2)) SC: O(n^2)
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> maxKSumCombinations(vector<int>& A, vector<int>& B, int K) {
        int N = A.size();
        vector<int> allSums;
        
        // Generate all possible sums
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                allSums.push_back(A[i] + B[j]);
            }
        }
        
        // Sort sums in descending order
        sort(allSums.begin(), allSums.end(), greater<int>());
        
        // Extract top K sums
        vector<int> result(allSums.begin(), allSums.begin() + K);
        
        return result;
    }
};


// optimal approach using max heap and set
// T.C : O(NlogN + Klogk)
// Intuition

// The largest possible sum is always max(A) + max(B).

// If we sort both arrays in descending order, then A[0] + B[0] is the maximum.

// The next candidates will be:

// (A[1] + B[0]) → take the next element in A

// (A[0] + B[1]) → take the next element in B

// So instead of generating all n² sums, we use a max heap to always pick the current largest sum
// and then expand only its neighbors.

// A set is used to avoid pushing the same (i, j) index pair more than once.

// This makes the approach efficient.

// Algorithm

// Sort both arrays A and B in descending order.

// Create a max heap that stores {sum, {i, j}}.

// Start with {A[0] + B[0], {0, 0}}.

// While K > 0:

// Extract the largest sum from the heap.

// Add it to the result.

// Push its neighbors:

// (i+1, j) → next element in A

// (i, j+1) → next element in B

// Make sure we don’t push duplicates using a set.

// Return the result.



class Solution {
public:
    vector<int> maxKSumCombinations(vector<int>& A, vector<int>& B, int K) {
        int N = A.size();

        // Step 1: Sort both arrays in descending order
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());

        // Max heap to store {sum, {i, j}}
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        // Set to keep track of visited index pairs (i, j)
        set<pair<int, int>> visited;

        // Step 2: Push the largest sum (A[0] + B[0]) into heap
        maxHeap.push({A[0] + B[0], {0, 0}});
        visited.insert({0, 0});

        vector<int> result;

        // Step 3: Extract K largest sums
        while (K-- && !maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();

            int sum = current.first;
            int i = current.second.first;
            int j = current.second.second;

            // Store the current maximum sum
            result.push_back(sum);

            // Step 4: Explore next candidates

            // Candidate 1: (i+1, j)
            if (i + 1 < N && visited.find({i + 1, j}) == visited.end()) {
                maxHeap.push({A[i + 1] + B[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            // Candidate 2: (i, j+1)
            if (j + 1 < N && visited.find({i, j + 1}) == visited.end()) {
                maxHeap.push({A[i] + B[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return result;
    }
};

// Complexity

// Sorting: O(N log N)

// Heap operations: Each push/pop → O(log N).

// We do this K times → O(K log N).

// Total Time Complexity: O(N log N + K log N)

// Space Complexity:

// Heap + Set store at most O(N) elements → O(N).