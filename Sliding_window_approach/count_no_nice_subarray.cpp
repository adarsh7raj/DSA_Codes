
// brute force approach :

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    
        int result=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
         int count_odd=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==1){
                    count_odd++;
                }
                if(count_odd==k){
                    result++;
                
                }
                
            }
        }
        return result;
    }
};

// optimal solution using sliding window it is similar to binary subarray sum
//TC:O(2n) and SC:O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    
        int result=0;
        int n=nums.size();
        int l=0;
        int r=0;
        int count_odd=0;
        int count_even=0;
        while(r<n){
        if(nums[r]%2==1){
            count_odd++;
        }
       while(l<r && (nums[l]%2==0 || count_odd>k)){

        if(nums[l]%2==0){
            count_even++;
        }
        else{
            count_even=0;
            count_odd--;
        }
        l++;
       }
        if(count_odd==k){
            result=result+1+count_even;
        }
        r++;
        }
        return result;
        }
        
    
};