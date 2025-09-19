
// TC : O(n^2)  SC : O(1)
// Selection Sort Algorithm
#include <iostream>
using namespace std;
/*
👉 Intuition:
Selection Sort works by repeatedly selecting the smallest element
from the unsorted part of the array and putting it at the beginning.
After each iteration, the boundary between the sorted and unsorted
parts of the array shifts by 1.

👉 Algorithm:
1. Start with the whole array as unsorted.
2. For each index i (from 0 to n-2):
   - Assume arr[i] is the minimum.
   - Search the rest of the array (i+1 to n-1) to find the actual minimum element.
   - Swap the found minimum with arr[i].
3. Repeat until the array is sorted.

👉 Why loop goes till n-2:
- On the second last step, the last element is already in its correct position automatically.
*/


// we do not need to pass the arr as reference (&) because array is always passed by reference
// for vectors we need to pass by reference (&) otherwise it will create a copy of the vector and then sort that copy only
void insertion_sort(int arr[],int n){
    for(int i=0;i<=n-2;i++){// n-2 because last element will be automatically sorted

        int mini=i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        swap(arr[i],arr[mini]);
    }
}

int main(){
    int arr[]={5,4,3,2,1};
    int n=5;
    insertion_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}