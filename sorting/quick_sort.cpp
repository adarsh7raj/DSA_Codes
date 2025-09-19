#include <iostream>
using namespace std;

/*
👉 Intuition:
Quick Sort is a Divide and Conquer algorithm. 
We pick a pivot element (here, the first element of the array/subarray) 
and rearrange the array such that:
  - All elements smaller than pivot go to its left
  - All elements greater than pivot go to its right
Then we recursively apply the same process to the left and right subarrays.
This way, the pivot ends up in its correct sorted position after partitioning.
*/

/*
Partition function:
- Pivot chosen: first element (arr[low])
- Two pointers approach:
    i -> scans from left to right for element > pivot
    j -> scans from right to left for element <= pivot
- Swap arr[i] and arr[j] if i < j (correct out-of-place elements)
- When pointers cross, swap pivot with arr[j] to place pivot in correct position
- Return pivot index
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[low];   // choose first element as pivot
    int i = low + 1;        // pointer starting just after pivot
    int j = high;           // pointer starting from end

    while (true) {
        // Move i to the right until an element > pivot is found
        while (i <= high && arr[i] <= pivot) i++;
        // Move j to the left until an element <= pivot is found
        while (j >= low && arr[j] > pivot) j--;

        if (i < j) {
            swap(arr[i], arr[j]); // swap elements that are on wrong sides
        } else {
            break; // pointers crossed → partitioning done
        }
    }
    swap(arr[low], arr[j]); // place pivot at its correct position
    return j;               // return pivot index for further recursion
}

/*
QuickSort function:
- Recursively sort subarrays before and after the pivot
- Base condition: if low >= high, array/subarray is of size 0 or 1 → already sorted
*/
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // partitioning index

        quickSort(arr, low, pi - 1);   // sort left subarray
        quickSort(arr, pi + 1, high);  // sort right subarray
    }
}

// Driver function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1); // sort the array

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

/*
Algorithm Step-by-Step:
1. Pick first element as pivot.
2. Rearrange elements: left < pivot, right > pivot.
3. Place pivot in correct position.
4. Recursively apply steps 1-3 to left and right subarrays.
5. Stop recursion when subarray size is 0 or 1.
Time Complexity:
- Best/Average: O(n log n)
- Worst (already sorted array with bad pivot): O(n^2)
*/
