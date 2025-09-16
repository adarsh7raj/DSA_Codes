//brute force approach : O(n):

int kthElement(vector<int>& a, vector<int>& b, int k) {
    // code here
    vector<int>ans;
    int n=a.size();
    int m=b.size();
    for(int i=0;i<n;i++){
        ans.push_back(a[i]);
    }
    for(int i=0;i<m;i++){
        ans.push_back(b[i]);
    }
    sort(ans.begin(),ans.end());
 return ans[k-1];
}


//better approach : O(logv.(logn+logm)):
  // code here
  int CountSmall(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int count = 0;
  // it counts number of elements <=x;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] <= x) {
            count = mid + 1;     // elements at index 0 to mid are ≤ x
            low = mid + 1;       // search in right half
        } else {
            high = mid - 1;      // search in left half
        }
    }

    return count;
}

int kthElement(vector<int>& a, vector<int>& b, int k) {
    int n = a.size();
    int m = b.size();

    // Assume arrays are sorted
    int low = min(a[0], b[0]);
    int high = max(a[n - 1], b[m - 1]);

    while (low <= high) {
        int mid = (low + high) / 2;
        
        int count = CountSmall(a, mid) + CountSmall(b, mid);

        if (count < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;  // This will be the k-th smallest element
}


//optimal solution : O(log(min(m,n)))

    //optimal O(log(n+m))
// We are going to apply binary search on the smaller array.
// Here mid1 isthe number of elements taken from nums1 into the left half.
//We want to partition the two sorted arrays (nums1 and nums2) into left half and right half such that:

//The total number of elements in the left half = k (where k is given).
// The totalnumber of elements in the right half =n-k (where n = n1 + n2).

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

int kthElement(vector<int>& a, vector<int>& b, int k) {
    int n1=a.size();
    int n2=b.size();
    int n=n1+n2;
    if(n1>n2){
        return kthElement(b,a,k);
    }
  
    
int low = max(0, k - n2);
int high = min(k, n1);
  
    while(low<=high){
    int l1=INT_MIN;
    int l2=INT_MIN;
    int r1=INT_MAX;
    int r2=INT_MAX;
        int mid1=(low+high)/2;
        int mid2=k-mid1;
        if(mid1>0 ){
            l1=a[mid1-1];
            
        }
        if(mid2>0){
            l2=b[mid2-1];
        }
        if(mid1<n1){
            r1=a[mid1];
            
        }
        if(mid2<n2){
            r2=b[mid2];
        }
        if(l1<=r2 && l2 <= r1){
        
          return   max(l1,l2);
            
      
        }
       else if(l1>r2){
            high=mid1-1;
        }
        else{
            low=mid1+1;
        }
    }
    return -1;
// This will be the k-th smallest element
}