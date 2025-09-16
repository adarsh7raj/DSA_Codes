// We are given an array arr[] and a window size k.
// 👉 For every contiguous subarray (window) of size k, we need to count how many distinct elements are present.
// Return these counts as a vector.
// Brute force approach: check each window separately
// TC: O(n*k) ~ O(n^2) in worst case, SC: O(k) (map to store elements)
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> ans;
        // Iterate over each possible window of size k
        for(int i = 0; i <= arr.size() - k; i++) {
            map<int,int> mp; // map stores frequency of elements in the window
            // Process window [i, i+k-1]
            for(int j = i; j < k+i; j++) {
                mp[arr[j]]++; // count frequency
            }
            ans.push_back(mp.size()); // number of distinct = map size
        }
        return ans;
    }
};

// 🔹 Intuition

// For every window, create a new map/set and count distinct elements.

// Easy but inefficient because we recompute counts from scratch for every window.

// 🔹 Time & Space Complexity

// TC: O(n*k) → in worst case ~ O(n²)

// SC: O(k) → map stores up to k elements for each window


/ Optimal solution using sliding window and hashmap
// TC: O(n), SC: O(k)
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> ans;
        unordered_map<int, int> freq; // stores frequency of elements
        int n = arr.size();

        // Step 1: Process the first window [0, k-1]
        for (int i = 0; i < k; ++i) {
            freq[arr[i]]++;
        }
        ans.push_back(freq.size()); // distinct count of first window

        // Step 2: Slide the window one element at a time
        for (int i = k; i < n; ++i) {
            // Remove outgoing element (i-k) remove the first element of the previous window
            freq[arr[i - k]]--;
            if (freq[arr[i - k]] == 0) // if the frequency becomes 0 remove the element from map
                freq.erase(arr[i - k]); // clean up if freq=0

            // Add new incoming element (i) add the last element of the new window
            freq[arr[i]]++;

            // Distinct count = size of freq map
            ans.push_back(freq.size());
        }
        return ans;
    }
};


// 🔹 Intuition
// Instead of recalculating for each window:

// Maintain a frequency map of current window.

// When the window slides:

// Remove one outgoing element.

// Add one new incoming element.

// Distinct count is simply the size of the map.

// 🔹 Time & Space Complexity
// TC:

// First window: O(k)

// Sliding over rest: O(n-k) (each insert/erase = O(1) avg in unordered_map)

// Total → O(n)

// SC: O(k) → at most k elements in the map