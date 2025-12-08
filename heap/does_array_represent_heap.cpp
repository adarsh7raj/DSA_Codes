// TC -> O(N)
// SC -> O(1)


class Solution {
  public:
  
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
       for(int i=0;i<n/2;i++){
           int parent =i;
           int left_child=2*i+1;
           int right_child=2*i+2;
           if(arr[parent]<arr[left_child] || arr[parent]<arr[right_child]){
               return false;
           }
       }
       return true;
    }
};