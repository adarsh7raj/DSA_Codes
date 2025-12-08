#include<iostream>
using namespace std;
// TC -> O(NlogN)
// SC -> O(1)
void Heapify(int arr[],int n,int index){
    int largest=index;
    int leftChild=2*index+1;
    int rightChild=2*index+2;

    if(leftChild<n && arr[leftChild]>arr[largest]){
        largest=leftChild;
    }
    if(rightChild<n && arr[rightChild]>arr[largest]){
        largest=rightChild;
    }
    if(largest!=index){
        swap(arr[largest],arr[index]);
        Heapify(arr,n,largest);
    }
    return;
}
void BuildMaxHeap(int arr[],int n){
   // step down:
   
   for(int i=n/2-1;i>=0;i--){
    Heapify(arr,n,i);
     
   }
}
void SortArray(int arr[],int n){
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        Heapify(arr,i,0);
    }
}
int main(){
    int arr[] = {3, 5, 1, 10, 2, 7};
    BuildMaxHeap(arr, 6); // this necessary to build the heap first 
    // then after that we find the max heap at root and swap it with last element
    // then again heapify the root element to maintain the heap property for remaining elements
    SortArray(arr, 6);
}