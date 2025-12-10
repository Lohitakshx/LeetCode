class Solution {
public:
    bool isSafe(vector<string> & board , int n, int row, int col){
        int rowDup = row;
        int colDup = col;

        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--, col--;
        }
        row = rowDup;
        col = colDup;
        while(col >= 0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        col = colDup;
        row = rowDup;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++, col--;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans , vector<string> & board , int n, int col){
        if(col == n) {
            ans.push_back(board);
            return ;
        }
        for(int row = 0; row<n; row++){
            if(isSafe(board, n, row, col)){
                board[row][col] = 'Q';
                solve(ans, board, n, col+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(ans, board , n, 0);
        return ans;
    }
};