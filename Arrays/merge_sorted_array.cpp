//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
//and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function,
// but instead be stored inside the array nums1. 
//To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements 
//that should be merged, and the last n elements are set to 0 and should be ignored. 
//nums2 has a length of n.
//optimal solution : O(n)+(n+m)log(n+m)
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            
            if(n==0){
                return;
            }
            for(int i=m;i<m+n;i++){
            
                    nums1[i]=nums2[i-m];
                
            }
            sort(nums1.begin(),nums1.end());
        }
    };

//optimal solution : 
// TC : O(nlogn + mlogm) + O(n+m) SC : O(1)
class Solution{
    public: 
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1;
        int right=0;
        while(left>=0 && right<n){
  if(nums1[left]>=nums2[right]){
    swap(nums1[left],nums2[right]);
    left--;
    right++;

  }
  else{
    break;
  }
        }
sort(num1.begin(),nums1.end());
sort(nums2.begin(),nums2.end());

for(int i=m;i<m+n;i++){
            
    nums1[i]=nums2[i-m];

}
    }
}

    // gap method approach:

    //two pointer approach : 
    // TC : O(n+m) SC : O(1)
    class Solution {
        public:
            void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
                int i = m - 1;             // Pointer for last valid element in nums1
                int j = n - 1;             // Pointer for last element in nums2
                int k = m + n - 1;         // Pointer for last position in nums1
        
                // Start filling from the back
                while (i >= 0 && j >= 0) {
                    if (nums1[i] > nums2[j]) {
                        nums1[k] = nums1[i];
                        i--;
                    } else {
                        nums1[k] = nums2[j];
                        j--;
                    }
                    k--;
                }
        
                // If any elements left in nums2, copy them
                while (j >= 0) {
                    nums1[k] = nums2[j];
                    j--;
                    k--;
                }
            }
        };
        