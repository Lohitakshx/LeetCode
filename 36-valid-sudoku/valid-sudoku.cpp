class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 3 arrays to track numbers in rows, columns, and boxes
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '1'; // convert char '1'-'9' to index 0-8
                int k = (i / 3) * 3 + (j / 3); // box index 0-8

                if(row[i][num] || col[j][num] || box[k][num])
                    return false; // duplicate found

                row[i][num] = col[j][num] = box[k][num] = true;
            }
        }
        return true;
    }
};
