//  brute force approach TC:O(n*m), SC:O(2)
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        // code here
         vector<int>ans(2,-1);
        
        for(int i=0;i<mat.size();i++){
         int count=0;
         for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==1){
                count++;
            }
         }
         if(count>ans[1]){
            ans[1]=count;
            ans[0]=i;
         }
        }
        if(ans[1]==0){
            return -1;
        }
        return ans[0]
    }
};


//TC:O(n+m), SC:O(1) most optimal approach
 int n = arr.size();
        int m = arr[0].size();

        int row = 0;
        int col = m - 1;
        int ans = -1;

        while (row < n && col >= 0) {
            if (arr[row][col] == 1) {
                ans = row;   // update answer
                col--;       // move left
            } else {
                row++;       // move down
            }
        }

        return ans;


        // we also do binary search in each row to find first occurrence of 1
        //TC: O(n log m), SC: O(1)
class Solution {
  public:
    int firstOccurrence(vector<int>& row) {
        int left = 0, right = row.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (row[mid] == 1) {
                ans = mid;          // potential answer
                right = mid - 1;   // search in left half
            } else {
                left = mid + 1;    // search in right half
            }
        }

        return ans;
    }

    int rowWithMax1s(vector<vector<int>> &mat) {
        int maxRowIndex = -1;
        int maxCount = 0;

        for (int i = 0; i < mat.size(); i++) {
            int firstOneIndex = firstOccurrence(mat[i]);
            if (firstOneIndex != -1) {
                int countOfOnes = mat[i].size() - firstOneIndex;
                if (countOfOnes > maxCount) {
                    maxCount = countOfOnes;
                    maxRowIndex = i;
                }
            }
        }

        return maxRowIndex;
    }