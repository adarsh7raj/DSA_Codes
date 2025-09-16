// TC : O(n):
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        int current =nums[0];
        for(int i=1;i<nums.size();i++){
              
                 if(current!=nums[i]){
                    
                    current=nums[i];
                    nums[count]=nums[i];
                    count++;
                 }
        }
        return count;
    }
};

// Two pointer approach : 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int i=0;
    int j=1;
    int n=nums.size();
    while(j<n){
        if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
        }
        j++;

    }
    return i+1;
  
    }
};