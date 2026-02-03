// first find the count of elements less than equal to mid in each row
// then sum up the counts of all rows
// if total count is less than equal to req then we have to move towards right side
// else we have to move towards left side
//we have to find the smallest number such that count of numbers less than equal to that number 
//is greater than (n*m)/2
class Solution {
  public:
  
  int upperBound(vector<int>& row, int target) {
    int low = 0, high = row.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (row[mid] <= target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int low = INT_MAX, high = INT_MIN;
        
    for (int i = 0; i < n; i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }

    int req = (n * m) / 2;

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        for (int i = 0; i < n; i++) {
            count += upperBound(mat[i], mid);
        }

        if (count <= req)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
    }
};
