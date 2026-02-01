// similar to book allocation problem
// just change the variable names and comments from book allocation to painter's partition problem

#include <vector>

 bool isPossible(vector<int>& arr,int students,int max_pages){
      int student_allocated=1;
      int sum=0;
      for(int i=0;i<arr.size();i++){
         if(sum+arr[i]>max_pages){
             student_allocated++;
             sum=arr[i];
         } 
         else{
             sum+=arr[i];
         }
      }
     
      if(student_allocated<=students){
          return true;
      }
      return false;
  }
int findLargestMinDistance(vector<int>& arr, int k) {
    
        int n=arr.size();
        if(n<k){
            return -1;
        }
        int sum=0;
        int l=*max_element(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int r=sum;
        while(l<=r){
            int  mid=l+(r-l)/2;
            if(isPossible(arr,k,mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }

    

