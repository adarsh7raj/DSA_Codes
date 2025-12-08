#include<iostream>
using namespace std;

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
    Heapify(arr,n,i);  //we can not call the heapify() from i=0 because the Because heapify must always be applied 
    //bottom-up:

// Heapify assumes that the subtrees(childs) of the current index are already heaps.

// If you start at index 0, its children (index 1 and 2) are not yet heapified, so the heap property may break.
     
   }
}
int main(){
    int arr[]={10, 5, 3, 2, 4};
    BuildMaxHeap(arr, 5);
}