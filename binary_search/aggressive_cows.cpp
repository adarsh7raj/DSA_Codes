


// simplest and cleanest binary search approach: O(nlog(max-min)):


class Solution {
  public:
  
  bool isPossible(vector<int>& stalls,int cows, int distance){
      int placed_cow=1;
      int last=stalls[0];
      for(int i=1;i<stalls.size();i++){
          if((stalls[i]-last)>=distance){
              placed_cow++;
              last=stalls[i];
          }
      }
      if(placed_cow>=cows){
          return true;
      }
      return false;
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int l=1;
        
        int r=stalls[n-1]-stalls[0];
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(isPossible(stalls,k,mid)){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return r;
    }
};




/*
=====================================================================
Problem: Aggressive Cows

Question:
----------
You are given a number of stalls in a straight line represented by an array 'stalls'.
You are also given a number of cows 'cows' that need to be placed in these stalls.  

Goal:
-----
Place all cows in such a way that the **minimum distance between any two cows is maximized**.

Constraints:
------------
- Cows must be placed in existing stalls.
- Each stall can hold at most one cow.

Example:
--------
stalls = [1, 2, 4, 8, 9], cows = 3

- Possible placement for max minimum distance: [1, 4, 8]
- Distances between cows: 4-1 = 3, 8-4 = 4
- Minimum distance = 3
- Answer = 3

=====================================================================
Intuition:
----------
0. In this code we taking the difference b/w any two stalls as the distance then trying to maximize the distance. 
// And to minimize the distance we first start the stall which are consicutive because the stalls array is sorted. 
1. To maximize the minimum distance, we want cows to be as far apart as possible.
2. For a given minimum distance 'd', we can check if it's possible to place all cows.
3. If it is possible for 'd', then it's also possible for any distance < d (monotonic property).
4. If it's not possible for 'd', then any distance > d is also impossible.
5. This property allows us to use **greedy placement** and also enables **binary search optimization**.

=====================================================================
Algorithm:
----------
1. Sort the stalls in ascending order to place cows sequentially.
2. Try placing cows starting from the first stall and moving greedily:
    - Place a cow at the first stall.
    - For each next stall, place a cow only if distance from last placed cow >= min_dist.
3. Count how many cows are placed:
    - If we can place all cows, the distance is feasible.
    - If not, distance is too large.
4. Brute-force approach: check every possible distance from 1 to (max stall - min stall)
5. Store the largest feasible distance as the answer.

=====================================================================
Brute-force Complexity:
-----------------------
- Outer loop: tries every distance d from 1 to max_possible_distance
- Inner loop: O(n) to check if cows can be placed
- Total complexity: O(n * (max - min))  → Can be slow for large stall positions
=====================================================================
*/

// Helper function to check if 'cows' can be placed with at least 'min_dist' apart
bool canPlaceCows(vector<int>& stalls, int cows, int min_dist) {
    // Place the first cow at the first stall
    int last_pos = stalls[0];
    int count = 1; // Number of cows placed so far

    // Start checking from the second stall onwards
    for (int i = 1; i < stalls.size(); i++) {
        // If current stall is at least min_dist away from last placed cow
        if (stalls[i] - last_pos >= min_dist) {
            count++;            // Place a cow here
            last_pos = stalls[i]; // Update the position of the last placed cow
        }
        // If all cows are already placed successfully, return true
        if (count >= cows) return true;
    }

    // Could not place all cows with given min_dist
    return false;
}

// Function to find the largest minimum distance (Brute-force approach)
int aggressiveCows(vector<int>& stalls, int cows) {
    // Step 1: Sort stalls to make sequential placement possible
    sort(stalls.begin(), stalls.end());

    // Step 2: Determine the maximum possible distance
    // The largest distance can't be more than distance between first and last stall
    int max_possible_distance = stalls.back() - stalls.front();

    int ans = 0; // Store the largest feasible distance

    // Step 3: Try every possible distance d from 1 to max_possible_distance
    for (int d = 1; d <= max_possible_distance; d++) {
        // Step 4: Check if it's possible to place all cows with distance d
        if (canPlaceCows(stalls, cows, d)) {
            ans = d;  // Store the largest feasible distance so far
        }
    }

    return ans;
}

/*
=====================================================================
Test Case Examples:
-------------------
1. stalls = [1, 2, 4, 8, 9], cows = 3
   Output: 3
   Explanation: Place cows at stalls 1, 4, 8 → min distance = 3

2. stalls = [1, 2, 3, 4, 5], cows = 2
   Output: 4
   Explanation: Place cows at stalls 1, 5 → min distance = 4

3. stalls = [5, 17, 100, 11], cows = 2
   Output: 95
   Explanation: Place cows at stalls 5 and 100 → min distance = 95

=====================================================================
Important Notes / Intuition Behind Code:
----------------------------------------
1. Always start from the **first stall** because greedy placement ensures maximum minimum distance.
2. `last_pos` keeps track of the last cow’s position to maintain the required `min_dist`.
3. `count >= cows` → early stopping to save unnecessary iterations.
4. Brute-force tries every possible distance → simple to understand but inefficient for large inputs.
5. Optimized approach: use **binary search** on distance instead of checking every value (reduces time complexity to O(n*log(max-min))).

*/


// optimal solution using binary search: O(nlog(max-min)):


#include <bits/stdc++.h>
using namespace std;

/*
=====================================================================
Problem: Aggressive Cows (Optimized Version using Binary Search)

Question:
----------
Given a number of stalls in a straight line (array 'stalls') and a number 
of cows 'cows', place all cows in such a way that the minimum distance 
between any two cows is maximized.  

Goal:
-----
Return the largest minimum distance possible between cows.

Example:
--------
stalls = [1, 2, 4, 8, 9], cows = 3

- Place cows at positions [1, 4, 8]
- Distances: 4-1 = 3, 8-4 = 4
- Minimum distance = 3 → Answer = 3

=====================================================================
Intuition:
----------
1. If a distance 'd' is possible to place all cows, then all distances < d are also possible.
2. If a distance 'd' is impossible, all distances > d are impossible.
3. This **monotonic property** allows binary search on the distance:
   - Search space: 1 to (max stall - min stall)
   - Check if distance 'mid' is feasible
   - Adjust search space accordingly
4. Use greedy placement in helper function to check feasibility.

=====================================================================
Algorithm:
----------
1. Sort the stalls in ascending order.
2. Initialize binary search: low = 1, high = max_possible_distance (last stall - first stall)
3. While low <= high:
   a. mid = (low + high)/2 → candidate minimum distance
   b. If mid is feasible (using helper), store it as potential answer and try larger distance (low = mid + 1)
   c. Else, try smaller distance (high = mid - 1)
4. Return the largest feasible minimum distance found.

=====================================================================
Time Complexity:
----------------
- Sorting stalls: O(n log n)
- Binary search on distance: O(log(max-min))
- Greedy check per mid: O(n)
- Total: O(n log n + n log(max-min)) → efficient for large inputs
=====================================================================
*/

// Helper function to check if 'cows' can be placed with at least 'min_dist' apart
bool canPlaceCows(vector<int>& stalls, int cows, int min_dist) {
    int last_pos = stalls[0];  // Place first cow in first stall
    int count = 1;              // Number of cows placed

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last_pos >= min_dist) {
            count++;            // Place a cow here
            last_pos = stalls[i]; // Update last cow position
        }
        if (count >= cows) return true; // Successfully placed all cows
    }

    return false; // Cannot place all cows with min_dist
}

// Optimized function using binary search
int aggressiveCows(vector<int>& stalls, int cows) {
    // Step 1: Sort stalls for sequential placement
    sort(stalls.begin(), stalls.end());

    // Step 2: Initialize binary search
    int low = 1;                        // Minimum possible distance
    int high = stalls.back() - stalls.front(); // Maximum possible distance
    int ans = 0;                         // Store largest feasible distance

    // Step 3: Binary search on distance
    while (low <= high) {
        int mid = low + (high - low) / 2; // Candidate minimum distance

        if (canPlaceCows(stalls, cows, mid)) {
            ans = mid;       // mid is feasible → store it
            low = mid + 1;   // Try larger distance to maximize
        } else {
            high = mid - 1;  // mid not feasible → try smaller distance
        }
    }

    return ans; // Largest minimum distance possible
}

/*
=====================================================================
Test Case Examples:
-------------------
1. stalls = [1, 2, 4, 8, 9], cows = 3
   Output: 3

2. stalls = [1, 2, 3, 4, 5], cows = 2
   Output: 4

3. stalls = [5, 17, 100, 11], cows = 2
   Output: 95

=====================================================================
Step-by-step Intuition:
----------------------
1. Sorting ensures we can place cows greedily from left to right.
2. Greedy placement ensures cows are **as far apart as possible**.
3. Binary search reduces the number of distance checks drastically compared to brute-force.
4. Monotonic property of feasibility makes binary search valid.
5. Each iteration tries a candidate distance and updates the answer accordingly.
=====================================================================
*/
