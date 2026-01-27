// TC: O(log N)
//SC: O(1)

class Solution {
  public:
  
  
     int  firstOcc(vector<int> &arr, int target){

       int left =0,right=arr.size()-1;
       int ans=-1;
        while(left<=right){
           int mid =left +(right-left)/2;

           if(target == arr[mid]){
            ans=mid;
            right=mid-1;
    
           }
           else if(target> arr[mid])left=mid+1;
           else right=mid-1;

        }
        return ans;
       }

       int secondOcc(vector<int> &arr, int target){

        int left =0,right=arr.size()-1;
        int ans=-1;
        while(left<=right){
           int mid =left +(right-left)/2;

           if(target == arr[mid]){

            ans=mid;
            left=mid+1;
           }
           else if(target> arr[mid])left=mid+1;
           else right=mid-1;
        }
        return ans;

        }
    int countFreq(vector<int>& nums, int target) {
        // code here
         vector<int>ans;
        ans.push_back(firstOcc(nums,target));
        ans.push_back(secondOcc(nums,target));
        if(ans[0]==-1){
            return 0;
        }
        return ans[1]-ans[0]+1;
        
    }
};
