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
       
      
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int>ans;
        ans.push_back(firstOcc(nums,target));
        ans.push_back(secondOcc(nums,target));
        return ans;
        
    }
};

// another approach : 
//TC: O(log N) + O(N) in worst case
//SC: O(1)

class Solution {
public:


      
    vector<int> searchRange(vector<int>& nums, int target) {

          int l=0;
        int r=nums.size()-1;
        vector<int>ans(2,-1);
        int k=0;
        if(nums.size()==0){
            return ans;
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
              k=mid;
             break;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
      int i=k;
        while( i>=0 && nums[i]==target){
            ans[0]=i;
            i--;
           
        }
        int j=k;
        while( j<nums.size() && nums[j]==target){
            ans[1]=j;
            j++;

        }
        
        
        if(ans.size()==1){
            ans.push_back(ans[0]);
            return ans;
        }

        return ans;

        
    }
};