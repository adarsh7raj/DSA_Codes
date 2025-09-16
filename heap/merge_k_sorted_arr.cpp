// brute force O(n^2):
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int>ans;
    for(int i=0;i<kArrays.size();i++){
        for(int j=0;j<kArrays[i].size();j++){
            ans.push_back(kArrays[i][j]);
        }
    }
  sort(ans.begin(),ans.end());
  return ans;
}

//  using merge sort : O(k*N): where N is the size of all arrays  SC : O(N)
 

#include <bits/stdc++.h>
using namespace std;

// Pass arr by reference
vector<int> Merge(vector<vector<int>>& arr, vector<int>& arr1, vector<int>& arr2, int count, int k) {
    vector<int> ans;
    int left = 0;
    int right = 0;
    while (left < arr1.size() && right < arr2.size()) {
        if (arr1[left] <= arr2[right]) {
            ans.push_back(arr1[left]);
            left++;
        } else {
            ans.push_back(arr2[right]);
            right++;
        }
    }
    while (left < arr1.size()) {
        ans.push_back(arr1[left]);
        left++;
    }
    while (right < arr2.size()) {
        ans.push_back(arr2[right]);
        right++;
    }
    
    count++;
    if (count == k) { // After merging all arrays
        return ans;
    } else {
       return  Merge(arr, ans, arr[count], count, k);
    }
}

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    if (k == 0) return {};   // Handle empty case
    if (k == 1) return kArrays[0];  // Only one array, directly return
    return Merge(kArrays, kArrays[0], kArrays[1], 1, k);
}

// min heap : O(N logk):

// create a structure to store the value along with its array index and element index

#include <bits/stdc++.h>
using namespace std;

struct MyData {
    int value;
    int i;
    int j;
    MyData(int v, int row, int col) : value(v), i(row), j(col) {}
};

// Comparator for the min-heap
struct Compare {
    bool operator()(const MyData& a, const MyData& b) {
        return a.value > b.value;  // smaller value = higher priority
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    vector<int> ans;
    priority_queue<MyData, vector<MyData>, Compare> minHeap;

    // Step 1: Push the first element of each array into the heap
    // smallest element will be at the top of minHeap
    for (int i = 0; i < kArrays.size(); i++) {
        if (!kArrays[i].empty()) {
            minHeap.push(MyData(kArrays[i][0], i, 0));
        }
    }

    // Step 2: Extract from heap and push next element from same array
    // because the next element will be either from the same array row or first element from another array row
    // in this way there will be at most k elements in the heap because one element is added and one is removed
    // so that is why TC is O(N log k)
    while (!minHeap.empty()) {
        MyData current = minHeap.top();
        minHeap.pop();
        ans.push_back(current.value);

        int nextIndex = current->j + 1;
        if (nextIndex < kArrays[current->i].size()) {
            minHeap.push(MyData(kArrays[current->i][nextIndex], current.i, nextIndex));
        }
    }

    return ans;
}
