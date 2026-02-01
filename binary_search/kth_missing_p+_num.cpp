
//TC: O(n) , SC: O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingCount = 0;
        int current = 1;
        int i = 0;

        while (missingCount < k) {
            if (i < arr.size() && arr[i] == current) {
                i++;
            } else {
                missingCount++;
                if (missingCount == k) {
                    return current;
                }
            }
            current++;
        }

        return -1; // unreachable
    }
};


//TC: O(log n) , SC: O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0;
        int r=n-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            int temp=arr[mid]-(mid+1);
            if(temp<k){
                l=mid+1;
            }
            else{
                r= mid-1;
            }
        }
        return l+k;
    }
};
