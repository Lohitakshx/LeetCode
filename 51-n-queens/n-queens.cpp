class Solution {
public:
    void putQueens(int col, int n, vector<string> &board,
                   vector<vector<string>> &ans,
                   vector<int> &leftRow,
                   vector<int> &upperDiag,
                   vector<int> &lowerDiag) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (!leftRow[row] && !upperDiag[row + col] && !lowerDiag[n - 1 + col - row]) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiag[row + col] = 1;
                lowerDiag[n - 1 + col - row] = 1;

                putQueens(col + 1, n, board, ans, leftRow, upperDiag, lowerDiag);

                // Backtrack
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiag[row + col] = 0;
                lowerDiag[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<int> leftRow(n, 0);        // Tracks occupied rows
        vector<int> upperDiag(2 * n - 1, 0); // Tracks "/" diagonals
        vector<int> lowerDiag(2 * n - 1, 0); // Tracks "\" diagonals

        putQueens(0, n, board, ans, leftRow, upperDiag, lowerDiag);

        return ans;
    }
};
