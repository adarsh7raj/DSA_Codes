// Time Complexity (TC)

// Your recursion works as follows:

// For each element in nums, you have two choices:

// Include it in the current subset.

// Exclude it from the current subset.

// So for n elements, the total number of recursive calls is:

// O(2^n)

// because each element doubles the number of possibilities (include/exclude).

// In each recursion when i == n, you push temp into ans.

// In the worst case, temp can have up to n elements.

// Copying temp into ans costs O(n) time.

// ✅ Therefore, total time complexity:

//  TC=O(n⋅2^n)
// 2️⃣ Space Complexity (SC)
// a) Auxiliary space (recursion stack):

// Maximum recursion depth = n (since i goes from 0 to n).

// Space used by recursion stack = O(n).

// b) Output space:

// Number of subsets = 
// O(n⋅2^n)
// Each subset can have up to n elements.

// Storing all subsets in ans takes O(n * 2^n) space.

// ✅ Therefore, total space complexity:

// SC=O(n⋅2^n)


class Solution {
public:
void subSet(int i,vector<int>& arr,set<vector<int>>& subset,vector<int>temp,int n){
    if(i>=n){
        subset.insert(temp);
        return;
    }
    temp.push_back(arr[i]);
    subSet(i+1,arr,subset,temp,n);
    temp.pop_back();
    subSet(i+1,arr,subset,temp,n);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>subset;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>temp;
        subSet(0,nums,subset,temp,n);
         vector<vector<int>> result(subset.begin(), subset.end());
         return result;
    }
};  