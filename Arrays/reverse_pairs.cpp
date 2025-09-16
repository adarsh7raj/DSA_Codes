//brute force approach : but this will give tle;
class Solution {
    public:
        int reversePairs(vector<int>& nums) {
            long long n=nums.size();
            int count=0;
            for(long long i=0;i<n;i++){
                for(long long j=i+1;j<n;j++){
                    if((long long)nums[i]>(long long )2*(nums[j])){
                        count++;
                    }
                }
            }
            return count;
        }
    };





    //optimal solution : using merge sort: TC: O(2nlogn)



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int count = 0;
    int reversePairs(vector<int>& nums) {
       
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        count += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
    }
//TC: O(n1+n2)
    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1, count = 0;
        for (int i = low; i <= mid; i++) {   //TC: O(n1)
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) {  //TC:O(n2)
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }

    void merge(vector<int>& arr, int low, int mid, int high) {
        int left = low, right = mid + 1;
        vector<int> temp;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
};
