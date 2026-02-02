
//TC: O(m * log(n))
//SC: O(1)

class Solution {
public:
int find_max(vector<vector<int>>& mat ,int col){
    int n=mat.size();
    int maxi=0;
    for(int i=1;i<n;i++){
        if(mat[i][col]>mat[maxi][col]){
            maxi=i;
        }
    }
    return maxi;
}

    vector<int> findPeakGrid(vector<vector<int>>& nums) {
        int m=nums.size();
        int n=nums[0].size();
        
          int l = 0, r = n - 1;
        vector<int>ans;
       

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int row=find_max(nums,mid);
            int left=mid>0?nums[row][mid-1]:-1;
            int right=mid<n-1?nums[row][mid+1]:-1;

            if ((nums[row][mid] > left) &&
                (nums[row][mid] > right)) {
                ans.push_back(row);
                ans.push_back(mid);
                return ans;
            }
            // rising slope → right
            else if ( nums[row][mid] < right) {
                l = mid + 1;
            }
            // falling slope or valley → left
            else if(nums[row][mid]<left) {
                r = mid - 1;
            }
            else{
                r=mid-1; // or l=mid+1;
            }
        }
         return ans;
    }
};