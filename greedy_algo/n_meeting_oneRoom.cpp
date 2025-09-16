//optimal solution :
// Algorithm

// Pair each meeting as (end_time, start_time) so we can sort by end time.

// Sort all meetings by ending time (earliest first).

// Select the first meeting (it always fits).

// For each next meeting:

// If its start > last_end → select it, update last_end.

// Return the count of selected meetings.
  // be performed in a meeting room.
  int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int, int>> meetings;

    // Step 1: Combine start and end times
    for (int i = 0; i < n; i++) {
        meetings.push_back({end[i], start[i]}); // sort by end time
    }

    // Step 2: Sort by meeting end time
    sort(meetings.begin(), meetings.end());

    // Step 3: Select meetings
    int count = 1;
    int last_end = meetings[0].first;

    for (int i = 1; i < n; i++) {
        if (meetings[i].second > last_end) {
            count++;
            last_end = meetings[i].first;
        }
    }

    return count;
}

//we can use comparator function to sort :

bool compareBySecond(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second; // if this returns true a comes before b;
}

sort(arr.begin(), arr.end(), compareBySecond);


// we can use lambda function :
sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;  // if true a comes before b;
});



// Complexity Analysis

// Sorting: O(n log n)

// Single pass selection: O(n)

// Time Complexity = O(n log n)

// Space Complexity = O(n) (for meetings vector)