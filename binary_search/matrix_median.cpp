//brute force approach: O(n^2):



vector<int>ans;
    int i=0;
    int j=0;
while(i<A.size()){
 int j=0;
 while(j<A[i].size()){
     ans.push_back(A[i][j]);
     j++;
 }
 i++;
}
sort(ans.begin(),ans.end());
int median=ans.size()/2;
return ans[median];


// optimal approach: 




//using minqueue;
// C++ program to find median of a matrix
// using Priority Queue
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int median(vector<vector<int>> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> minHeap;
    int cnt = 0, res = -1;

    // calculate median index
    int mid = (r * c) / 2;

    // Push the first element of each row into the min-heap
    for (int i = 0; i < r; i++) {
        minHeap.push({mat[i][0], {i, 0}});
    }

    // Extract elements from the min-heap to find the median
    while (cnt <= mid) {
        auto top = minHeap.top();
        minHeap.pop();
        int row = top.second.first;
        int col = top.second.second;
        res = top.first;
      	cnt++;

        // If there are more elements in the row, push the next element
        if (col + 1 < c) { 
            minHeap.push({mat[row][col + 1], {row, col + 1}});
        }
    }
    return res;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << median(matrix);
    return 0;
}


int upper_bound(vector<int>& arr, int x) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= x) {
            low = mid + 1;
        } else {
            high = mid-1;
        }
    }
    return low;
}

int median(vector<vector<int>> &matrix) {
    int low=1;
    int high=1e9;
    int r=matrix.size();
    int c=matrix[0].size();
    int median_pos=(r*c+1)/2;
    while(low<=high){
        int mid=(low+high)/2;
        int count=0;
        for(int i=0;i<r;i++){
            count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }
        if(count<median_pos){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}