// Why no extra conditions for the first two traversals?

// Left → Right (top row)

// When you start a loop, you are guaranteed that top <= bottom (checked at the while condition).

// So there’s always at least one row left to print.

// ✅ No extra condition needed.

// Top → Bottom (right column)

// Similarly, because left <= right from the while condition, there’s always at least one column.

// ✅ No extra condition needed.

// 🔁 Why do we need extra conditions for the last two traversals?

// Right → Left (bottom row)

// After we shrink top++ and right--, it might happen that top > bottom.

// Example: Single-row matrix like [[1, 2, 3, 4]].

// After the top row is traversed, top = 1, bottom = 0.

// If we don’t check if (top <= bottom), we’ll try to traverse a non-existent row → ❌ bug.

// Bottom → Top (left column)

// After we shrink bottom-- and left++, it might happen that left > right.

// Example: Single-column matrix like

// [[1],
//  [2],
//  [3]]


// After first column traversal, left = 1, right = 0.

// Without if (left <= right), we’ll again traverse a non-existent column → ❌ bug.

//TC : O(m*n) SC : O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int>ans;
         int m=matrix.size();
         int n=matrix[0].size();
         int k=0;
         int top=0;
         int bottom=m-1;
         int left=0;
         int right=n-1;
         while(top<=bottom && left<=right){
    for(int i=left;i<=right;i++){
        ans.push_back(matrix[top][i]);
    }
    top++;
    for(int i=top;i<=bottom;i++){
        ans.push_back(matrix[i][right]);
    }
    right--;
    if(top<=bottom){
 for(int i=right;i>=left;i--){
        ans.push_back(matrix[bottom][i]);
    }
    bottom--;
    }
   if(left<=right){
 for(int i=bottom;i>=top;i--){
        ans.push_back(matrix[i][left]);
        
    }
    left++;
   }
   
         }
     
        return ans;
    }
};