class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n=nums.size();
            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-i-1;j++){
                    if(nums[j]>nums[j+1]){
                        swap(nums[j],nums[j+1]);
                    }
                }
            }
        }
    };


    //better solution : O(2n)

    class Solution {
        public:
            void sortColors(vector<int>& nums) {
                int n=nums.size();
                int count_zero=0;
                int count_one=0;
                int count_two=0;
                for(int i=0; i<n;i++){
                if(nums[i]==0){
                    count_zero=count_zero+1;
                }
                if(nums[i]==1){
                    count_one=count_one+1;
                }
                if(nums[i]==2){
                    count_two=count_two+1;
                }
              
                }
                for(int j=0;j<count_zero;j++){
                    nums[j]=0;
                }
                
                for(int k=count_zero;k<count_zero+count_one;k++){
                    nums[k]=1;
                }
                for(int l=count_zero+count_one;l<count_zero+count_one+count_two;l++){
                    nums[l]=2;
                }
        };
        };


        //optimal solution O(n) Dutch national flag algo

        // This question can be divided in three parts 
        // 0 to [00000] low-1 and low to [1111] mid-1 and mid to [010011002210] high and high + 1 to [22222] n-1 


        class Solution {
            public:
                void sortColors(vector<int>& nums) {
                    int n = nums.size();
                    int low = 0, mid = 0, high = n - 1;
            
                    while (mid <= high) {
                        if (nums[mid] == 0) {
                            swap(nums[low], nums[mid]);
                            low++;
                            mid++;
                        } 
                        else if (nums[mid] == 1) { // Use else if to prevent multiple conditions
                            mid++;
                        } 
                        else { // When nums[mid] == 2
                            swap(nums[mid], nums[high]);
                            high--;
                            // **DO NOT** increment `mid` here. It may still be `2` after swapping.
                        }
                    }
                }
            };
            