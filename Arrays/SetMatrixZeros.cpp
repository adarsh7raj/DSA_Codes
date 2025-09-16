// Brute force approach with O(n^3) time complexity.
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();        // Number of rows
    int n = matrix[0].size();     // Number of columns

    // Step 1: Mark rows and columns that need to be zeroed
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                // Mark entire row
                for (int k = 0; k < n; k++) {
                    if (matrix[i][k] != 0) {
                        matrix[i][k] = -69;
                    }
                }
                // Mark entire column
                for (int l = 0; l < m; l++) {
                    if (matrix[l][j] != 0) {
                        matrix[l][j] = -69;
                    }
                }
            }
        }
    }

    // Step 2: Convert all -69 markers to 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -69) {
                matrix[i][j] = 0;
            }
        }
    }
}




// Better approach with O(n^2) time complexity
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();    // Number of rows
    int n = matrix[0].size(); // Number of columns

    vector<bool> row(m, false); // Track rows to be set to zero
    vector<bool> col(n, false); // Track columns to be set to zero

    // Step 1: Mark rows and columns that should be zero
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    // Step 2: Set marked rows and columns to zero
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}



// optimal solution : TC: O(m*n) SC:O(1):

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check first row and first col separately as they cause the problem 
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) 
                firstColZero = true;
        }

        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) 
                firstRowZero = true;
        }
   
// start from second row and second column and check if any element has zero if it has mark the first row and column of that element.

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

  // now each element check if there first column  or first row is zero if they are then mark that element as zero
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
          // now finally mark the first row and first  column as zero if any of the element of first row and column are zero

        if(firstRowZero) {
            for(int j = 0; j < n; j++) 
                matrix[0][j] = 0;
        }
        if(firstColZero) {
            for(int i = 0; i < m; i++) 
                matrix[i][0] = 0;
        }
    }
};
