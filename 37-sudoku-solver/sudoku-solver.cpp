#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Boolean arrays to keep track of constraints
    bool row[9][10];   // row[i][num] = true if num exists in row i
    bool col[9][10];   // col[j][num] = true if num exists in col j
    bool box[9][10];   // box[k][num] = true if num exists in box k

    void solveSudoku(vector<vector<char>>& board) {
        // Initialize constraints arrays
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(box, false, sizeof(box));

        // Fill constraints based on initial board
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    row[i][num] = true;
                    col[j][num] = true;
                    box[(i/3)*3 + j/3][num] = true;
                }
            }
        }

        // Start solving
        solve(board, 0, 0);
    }

private:
    bool solve(vector<vector<char>>& board, int i, int j) {
        if(j == 9){ // Move to next row
            i++; j = 0;
        }
        if(i == 9) return true; // Solved entire board

        if(board[i][j] != '.') return solve(board, i, j+1); // Skip filled cells

        for(int num = 1; num <= 9; num++){
            if(!row[i][num] && !col[j][num] && !box[(i/3)*3 + j/3][num]){
                // Place number
                board[i][j] = num + '0';
                row[i][num] = col[j][num] = box[(i/3)*3 + j/3][num] = true;

                if(solve(board, i, j+1)) return true; // Recurse

                // Backtrack
                board[i][j] = '.';
                row[i][num] = col[j][num] = box[(i/3)*3 + j/3][num] = false;
            }
        }

        return false; // No valid number found, backtrack
    }
};