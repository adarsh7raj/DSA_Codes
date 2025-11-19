// brute force approach : 
// TC:O(n^2):
// SC:O(1):

// this will give TLE for large inputs
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
          int maxi=0;
        for(int i=0;i<nums.size();i++){
            int zeros=0;
            int ones=0;
          
            for(int j=i;j<nums.size();j++){
                if(zeros>k){
                    break;
                }
                if(nums[j]==0){
                    zeros++;
                }
                else{
                    ones++;
                }
            }
            if(zeros>k){
        maxi=max(maxi,ones+zeros-1);
            }
              else{
                maxi=max(maxi,ones+zeros);
              } 
            
        }
        return maxi;
    }
};

// optimal solution : using sliding window approach
// TC:O(n):
// SC:O(1):


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int maxi=0;
       int l=0;
       int r=0;
       int zeros=0;
       while(r<nums.size()){
        if(nums[r]==0){
            zeros++;
        }
        if(zeros>k){
            if(nums[l]==0){
                
                zeros--;
            }
            l++;
        }
        else{
            maxi=max(maxi,r-l+1);
        }
        r++;
       }
        return maxi;
    }
};