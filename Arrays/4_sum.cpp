//brute force this will give TLE:

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        // Use long long to prevent overflow
                        if ((long long)nums[i] + nums[j] + nums[k] + nums[l] == target) {
                            vector<int> arr = {nums[i], nums[j], nums[k], nums[l]};
                            sort(arr.begin(), arr.end()); // Sort before inserting into set
                            ans.insert(arr);
                        }
                    }
                }
            }
        }
        
        return vector<vector<int>>(ans.begin(), ans.end()); // Convert set to vector
    }
};
//better approach: O(n^3logn):
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                map<long long, int> m; 
                for (int k = j + 1; k < n; k++) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k];

                    if (m.count((long long)target - sum)) {
                        vector<int> arr = {nums[i], nums[j], nums[k], (int)(target - sum)};
                        sort(arr.begin(), arr.end());
                        ans.insert(arr);
                    }
                    m[nums[k]] = k;
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

//optimal solution: we will use two pointer approach in this question:  O(n^3)

#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
           if(i>0 && nums[i]==nums[i-1]){
            continue;
           }
            for(int j=i+1;j<n;j++){
                if(j>1+i && nums[j]==nums[j-1]){
                    continue;
                }
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                
                    if(sum==target){
                     vector<int> arr={nums[i],nums[j],nums[k],nums[l]};
                     ans.push_back(arr);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]){
                            k++;
                        }
                        while(k<l && nums[l]==nums[l+1]){
                            l--;
                        }
                    }
                    else if(sum<target){
                     k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
};
};


