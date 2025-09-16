// We are given two arrays:

// arr[] → arrival times of trains

// dep[] → departure times of trains

// 👉 We must return the minimum number of platforms required so that no train has to wait.

// 🔹 Intuition

// When a train arrives, it needs a platform.

// When a train departs, it frees a platform.

// The answer = maximum number of trains on the station at the same time.

// 1️⃣ Brute Force Approach (O(n²))
// 🔹 Algorithm

// Pair each train → (arrival, departure).

// Sort trains by arrival time in ascending order.

// Maintain a map of platform → departure time.

// For each new train:

// Try to fit it into an existing platform (if its arrival > last departure).

// If not possible, add a new platform.

// Return total platforms used.

// 🔹 Code with comments
// Brute force approach: O(n^2)




static bool compareBySecond(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first; // Sort by arrival time (ascending)
}

int findPlatform(vector<int>& arr, vector<int>& dep) {
    int platform = 1; // Start with 1 platform for first train
    bool platform_found = false;
    vector<pair<int,int>> timings;

    // Pair each train's arrival & departure
    for (int i = 0; i < arr.size(); i++) {
        timings.push_back({arr[i], dep[i]});
    }

    // Sort trains by arrival time
    sort(timings.begin(), timings.end(), compareBySecond);

    // Map of platforms -> current train's departure time
    map<int,int> platforms;
    platforms[platform] = timings[0].second;

    // Process remaining trains
    for (int i = 1; i < arr.size(); i++) {
        for (auto it : platforms) {
            // If current train can use this platform (arrival > departure)
            if (timings[i].first > it.second) {
                platforms[it.first] = timings[i].second;
                platform_found = true;
                break;
            }
        }

        // If no free platform → add a new one
        if (!platform_found) {
            platform++;
            platforms[platform] = timings[i].second;
        }
        platform_found = false;
    }

    return platform;
}

// 🔹 Complexity

// Sorting: O(n log n)

// Nested loop (checking each platform): O(n²) in worst case

// TC = O(n²)

// SC = O(n) (for map of platforms)



// Priority Queue Approach (O(n log n))
// 🔹 Algorithm

// Pair (arrival, departure) for each train and sort by arrival time.

// Use a min-heap (priority_queue with greater<int>) to store departure times of trains currently on platforms.

// Heap top = train that leaves the earliest.

// For each train:

// If its arrival > earliest departure (heap top), pop that platform (train left).

// Push current train’s departure time into heap.

// At the end → pq.size() = number of platforms needed.

// 🔹 Code with comments
// Optimized approach: O(n log n) using min-heap



static bool compareBySecond(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first; // Sort by arrival time
}

int findPlatform(vector<int>& arr, vector<int>& dep) {
    vector<pair<int,int>> timings;

    // Pair each train
    for (int i = 0; i < arr.size(); i++) {
        timings.push_back({arr[i], dep[i]});
    }

    // Sort trains by arrival
    sort(timings.begin(), timings.end(), compareBySecond);

    // Min-heap to track earliest departure
    priority_queue<int, vector<int>, greater<int>> pq;

    // Push first train's departure
    pq.push(timings[0].second);

    for (int i = 1; i < arr.size(); i++) {
        // If current train arrives after earliest departure → reuse platform
        if (timings[i].first > pq.top()) {
            pq.pop();
        }
        // Assign platform to current train
        pq.push(timings[i].second);
    }

    // Number of active platforms = heap size
    return pq.size();
}

// 🔹 Complexity

// Sorting: O(n log n)

// Each heap push/pop: O(log n) → total O(n log n)

// TC = O(n log n)

// SC = O(n) (heap storage)




// Two-Pointer Approach (O(n log n))
// 🔹 Algorithm

// Sort arr[] and dep[] arrays individually.

// Use two pointers i (arrival), j (departure).

// Traverse:

// If arr[i] <= dep[j] → new train arrived → need new platform (count++, i++).

// Else → a train left (count--, j++).

// Update maxcount = max(maxcount, count).

// Return maxcount.

// 🔹 Code with comments
// Optimal approach: O(n log n) using two pointers




int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0;  // pointers
    int count = 0;     // current trains at station
    int maxcount = 0;  // max platforms required

    while (i < n) {
        if (arr[i] <= dep[j]) {
            // New train arrives before earliest departs → need platform
            count++;
            i++;
        } else {
            // A train departs → free platform
            count--;
            j++;
        }
        maxcount = max(maxcount, count);
    }

    return maxcount;
}

// 🔹 Complexity

// Sorting: O(n log n)

// Traversal: O(n)

// TC = O(n log n)

// SC = O(1) (just variables, no extra DS)