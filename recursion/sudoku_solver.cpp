

// TC : O(9^m) where m is the number of empty cells in the board
// SC : O(1) for the board, O(m) for the recursion stack

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check the row
            if (board[row][i] == c) return false;

            // Check the column
            if (board[i][col] == c) return false;

            // Check the 3x3 subgrid
            int subgridRow = 3 * (row / 3) + i / 3;
            int subgridCol = 3 * (col / 3) + i % 3;
            if (board[subgridRow][subgridCol] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, row, col, c)) {
                            board[row][col] = c; 

                            if (solve(board)){
                                return true;
                            }
                             
                            else {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;  // No valid digit could be placed 
                }
            }
        }
        return true;  // Board solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
