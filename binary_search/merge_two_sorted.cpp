//brute force (nlogn):
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n=nums1.size();
            int m=nums2.size();
            vector<int>ans;
            for(int i=0;i<n;i++){
                ans.push_back(nums1[i]);
            }
            for(int j=0;j<m;j++){
                ans.push_back(nums2[j]);
            }
            sort(ans.begin(),ans.end());
            if(ans.size()%2){
                int index=ans.size()/2;
                return ans[index];
            }
            else{
                int index=ans.size()/2;
                double ans_median=(ans[index-1]+ans[index])/2.0;
                return ans_median;
    
                
            }
            return 0;
        }
    };

    //optimal O(log(n+m))

//We want to partition the two sorted arrays (nums1 and nums2) into left half and right half such that:

//The total number of elements in the left half = (n+1)/2 (where n = n1 + n2).

// Every element in the left half ≤ every element in the right half.

// Then, the median is easy:

// If n is odd → the max of the left half.

// If n is even → the average of max(left half) and min(right half).

// Variables Meaning

// mid1 → how many elements we take from nums1 into the left half.

// mid2 → how many elements we take from nums2 into the left half.
// (Notice: mid1 + mid2 = LeftSize)

// Now, from these partitions, we define boundaries:

// l1 → the last element on the left of nums1.
// (nums1[mid1 - 1] if mid1 > 0, otherwise -∞)

// r1 → the first element on the right of nums1.
// (nums1[mid1] if mid1 < n1, otherwise +∞)

// l2 → the last element on the left of nums2.
// (nums2[mid2 - 1] if mid2 > 0, otherwise -∞)

// r2 → the first element on the right of nums2.
//(nums2[mid2] if mid2 < n2, otherwise +∞)

    class Solution {
        public:
            double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
                int n1=nums1.size();
                int n2=nums2.size();
                int n=n1+n2;
                if(n1>n2){
                    return findMedianSortedArrays(nums2,nums1);
                }
                int LeftSize=(n+1)/2;
                int low=0;
                int high=n1;
              
                while(low<=high){
                int l1=INT_MIN;
                int l2=INT_MIN;
                int r1=INT_MAX;
                int r2=INT_MAX;
                    int mid1=(low+high)/2;
                    int mid2=LeftSize-mid1;
                    if(mid1>0 ){
                        l1=nums1[mid1-1];
                        
                    }
                    if(mid2>0){
                        l2=nums2[mid2-1];
                    }
                    if(mid1<n1){
                        r1=nums1[mid1];
                        
                    }
                    if(mid2<n2){
                        r2=nums2[mid2];
                    }
                    if(l1<=r2 && l2 <= r1){
                        if(n%2){
                      return   max(l1,l2);
                        }
                        else{
                           return  (max(l1,l2)+min(r1,r2))/2.0;
                        }
                    }
                   else if(l1>r2){
                        high=mid1-1;
                    }
                    else{
                        low=mid1+1;
                    }
                }
                return 0;
            }
        };