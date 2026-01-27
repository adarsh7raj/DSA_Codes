// TC : O(log N)
// SC : O(1)

// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
         int mini=INT_MAX;
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]>=x){
                mini=min(mini,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return mini==INT_MAX ? -1 :mini;
    }
};