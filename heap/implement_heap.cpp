#include<iostram>
using namespace std;

class MaxHeap {
    int * arr;
    int size; // total number of elements present in the heap
    int totalSize;// total size of the array
    public :
    MaxHeap(int n) {
        arr = new int[n];
        size = 0;
        totalSize = n;
    }
    void heapify(int index){
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if(leftChild < size && arr[leftChild] > arr[largest]){
            largest = leftChild;
        }
        if(rightChild < size && arr[rightChild] > arr[largest]){
            largest = rightChild;
        }
        if(largest != index){
            swap(arr[largest], arr[index]);
            heapify(largest);
        }
        return;
    }
    void insert(int value){
        if(size == totalSize){
            cout<<"Heap is full"<<endl;
            return;
        }
        size++;
        int index = size - 1;
        arr[index] = value;

        while(index > 0){
            int parentIndex = (index - 1) / 2;
            if(arr[parentIndex] < arr[index]){
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            } else {
                return;
            }
        }
    }
    void delete(){
        if(size == 0){
            cout<<"Heap is empty"<<endl;
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        if(size == 0){
            return;
        }
        int index = 0;
       heapify(index);
    }
}
