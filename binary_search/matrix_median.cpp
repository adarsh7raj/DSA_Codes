



// brute force approach TC:O(n+m), SC:O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int>temp;
       int l=0;
       int r=0;
       int n=nums1.size();
       int m=nums2.size();
       while( l<n && r<m){
      if(nums1[l]>=nums2[r]){
        temp.push_back(nums2[r]);
        r++;
      }
      else{
        temp.push_back(nums1[l]);
        l++;
      }
       }

       while(l<n){
         temp.push_back(nums1[l]);
         l++;
       }
       while(r<m){
        temp.push_back(nums2[r]);
        r++;
       }
       int len=temp.size();
       if(len%2==1){
        return temp[len/2];
       }
       return (temp[len/2-1]+temp[len/2])/2.0;
    }
};

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



//optimal approach: TC: O(log(max - min) )

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();
        
        int low = 0, high = m;
        while(low <= high) {
             //(m+n+1)/2 is the total elements needed in left part
            int Px = low + (high-low)/2; // elements from nums1
            int Py = (m+n+1)/2 - Px;    // elements from nums2
            
            int x1  = (Px == 0) ? INT_MIN : nums1[Px-1];
            int x3 = (Px == m) ? INT_MAX : nums1[Px];
            
            int x2  = (Py == 0) ? INT_MIN : nums2[Py-1];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];
            
            if(x1 <= x4 && x2 <= x3) {
                if((m+n)%2 == 0)
                    return (max(x1, x2) + min(x3, x4))/2.0;
                
                return max(x1, x2);
            } else if(x1 > x4) {
                high = Px-1;
            } else {
                low = Px+1;
            }
        }
        
        return -1;
    }
};