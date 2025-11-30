// brute force approach :
// TC : O(n^2) and SC: O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==goal){
                    count++;
                }
            }
        }
        return count;
    }
};

// optimal solution using map
// TC : O(n) and SC: O(n)



class Solution {
    public:
        int subarraySum(vector<int>& arr,int k) {
            int n = arr.size();
            map<int,int>m;
            int sum=0;
            int count=0;
            for(int i=0;i<n;i++){
                sum=sum+arr[i];
                if(sum==k){
                    count++;
    
                }
                int rem=sum-k;
                if(m.count(rem)){
                    count=count+m[rem];
                }
                m[sum]++;
            }
            return count;
        }
    };
    


// optimal solution using sliding window
//TC:O(2n) and SC:O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       int n = nums.size();
            
            int sum=0;
            int count=0;
            int l=0;
            int r=0;
            int count_zero=0;
            while(r<n){
                sum+=nums[r];

                //  we will add all prefix zeros to count when we get sum==goal
                while(l<r && (nums[l]==0 || sum>goal)){
                    if(nums[l]==0){
                        count_zero++;
                    }
                    else{
                        count_zero=0;
                    }
                    sum-=nums[l];
                    l++;
                }
                if(sum==goal){
                    count=count+1+count_zero;
                }
                r++;
            }
            return count;
    
}
};