//  brute force solution : O(n^2)

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int n=nums.size();
            int count=0;
            int result=0;
           for(int i=0;i<n-1;i++){
            for(int j=i;j<n-1;j++){
             if(nums[i]==nums[j+1]){
                count++;
             }
             if(count==1){
                result=nums[i];
                return result;
             }
            }
           } 
        return  result;
    }
    };

    // better solution : Hashing method TC: O(n) SC: O(n): in this approach we make frequency array with all element to zero and each time we access the array elements we increase the frequency of the elements by one and some element we get frequency as two we return that element.
 class Solution{
    public:
    int findDuplicate(vector<int>&nums){
        int n=nums.size();
        int vector<int>arr(n,0);
        for(int i=0;i<nums.size();i++){
            if(arr[nums[i]]==0){
                arr[nums[i]]=1;
            }
            else{
                return nums[i];
            }
           
        }
    }
 }


    //optimal solution: TC: O(n) SC : O(1):
 //This aproach is called Floyd tortise hare method;
 // take two pointers slow and fast move slow by one and fast by two, stop when slow=fast, make fast =nums[0] 
 // after that move slow and fast by one ;

    class Solution {
        public:
            int findDuplicate(vector<int>& nums) {
                int fast=nums[0];
                int slow=nums[0];
                do{
                    slow=nums[slow];
                    fast=nums[nums[fast]];
                }
                while(slow!=fast);  // This first phase will find the cycle. 
                fast=nums[0];
                while(slow!=fast){   // This phase will help  to find the first element of the cycle and that will be our repeated number 
                    slow=nums[slow];
                    fast=nums[fast];
                }
                return slow;
            }
        };

