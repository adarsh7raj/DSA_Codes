/*
👉 Intuition:
Bubble Sort works by repeatedly swapping adjacent elements if they are in the wrong order.
After each full pass through the array, the largest element "bubbles up" to its correct position at the end.
We repeat this process until all elements are sorted.

👉 Algorithm:
1. Start from the end of the array and move backwards (outer loop).
2. In each pass, compare adjacent elements (arr[j] and arr[j+1]).
3. If arr[j] > arr[j+1], swap them.
   - This ensures the largest element in the unsorted part moves to the end of that part.
4. Keep reducing the unsorted portion by 1 (since the last element is already in correct place).
5. Repeat until the whole array is sorted.
*/

#include<iostream>
using namespace std;

void bubble_sort(int arr[],int n){
    for(int i=n-1;i>=0;i--){

        
        for(int j=0;j<=i-1;j++){
           if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
           }
        }
       
    }
}

int main(){
    int arr[]={5,4,3,2,1};
    int n=5;
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}