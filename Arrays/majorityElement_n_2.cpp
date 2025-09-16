//brute force approach:
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int n=nums.size();
            int count =1;
            int result=0;
            if(n==1){
                return nums[0];
            }
            for(int i=0;i<n;i++){
             for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                 
                }
             }
                if(count>(n/2)){
                         result=nums[i];
                        return result;
                    }
                    else{
                        count=1;
                    }
            }
            return result;
        }
    };

    //better approach using maps: 
    class Solution {
        public:
            int majorityElement(vector<int>& nums) {
                int n=nums.size();
                map<int,int> m;
                for(int i=0;i<n;i++){  // TC is here O(nlogn) because we are using ordered map it has TC O(logn);
                m[nums[i]]++;
            }
            for(auto it:m){ //TC is O(n) here.
                if(it.second>(n/2)){
                    return it.first;
                }
            }
            return -1;
        };
        };

    //optimal approach : Moore's voting method;
    class Solution {
        public:
            int majorityElement(vector<int>& nums) {
                int n=nums.size();
                int element=nums[0];
                int count=0;
                for(int i=0;i<n;i++){ 
                    if(nums[i]==element){
                        count++;
                    }
                    else{
                        count--;
                    }
                    if(count==0){ //
                        element=nums[i];
                        count++;
                    }
            }
         return element;
        
        };
        };
