
// brute force approach O(n^2) time complexity.
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    // Write your code here.
  
    int count =0;
    for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
           if(arr[i]>arr[j]){
               count++;
           }
       }
    }
    return (long long)count;
}

//optimal solution : using merge sort : TC: O(nlogn)


#include <bits/stdc++.h>
using namespace std;

long long inversionCount = 0; 

void merge(long long *arr, int low, int mid, int high) {
    int left = low, right = mid + 1;
    vector<long long> temp;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
            
        } else {
            temp.push_back(arr[right]);
            inversionCount += (mid - left + 1); // Count inversions
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy merged elements back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(long long *arr, int low, int high) {
    if (low >= high) return; // Base case

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

long long getInversions(long long *arr, int n) {
    inversionCount = 0; // Reset count before sorting
    mergeSort(arr, 0, n - 1);
    return inversionCount;
}


