class Solution {
public:
    bool isSafe(int n, int row, vector<string> &board, int col){
        int colDup = col;
        int rowDup = row;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--,col--;
        }
        col = colDup;
        row = rowDup;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        col = colDup;
        row = rowDup;
        while(col>=0 && row<n){
            if(board[row][col]=='Q') return false;
            col--,row++;
        }
        return true;
    }
    void puttingQueen(int n, vector<vector<string>>& ans, vector<string> &board, int col){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++){
            if(isSafe(n, row, board, col)){
                board[row][col]='Q';
                puttingQueen(n, ans, board, col+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(auto &row : board){
            row = s;
        }
        puttingQueen(n, ans, board, 0);
        return ans;
    }
};