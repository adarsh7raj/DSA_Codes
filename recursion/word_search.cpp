// brute force 
class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int i, int j, int k, vector<vector<bool>>& visited) {
        if (k == word.size()) return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] != word[k])
            return false;

        visited[i][j] = true;

        bool found = solve(board, word, i+1, j, k+1, visited)
                  || solve(board, word, i-1, j, k+1, visited)
                  || solve(board, word, i, j+1, k+1, visited)
                  || solve(board, word, i, j-1, k+1, visited);

        visited[i][j] = false;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, word, i, j, 0, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
