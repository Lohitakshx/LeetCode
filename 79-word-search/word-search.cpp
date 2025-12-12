class Solution {
public:

    bool dfs(vector<vector<char>> & board, string& word, int i, int j, int idx, vector<vector<bool>>& vis){
        if (idx == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[idx] || vis[i][j]) return false;

        vis[i][j] = true;
        bool found = 
        dfs(board , word, i+1, j, idx+1, vis) ||
        dfs(board , word, i, j+1, idx+1, vis) ||
        dfs(board , word, i-1, j, idx+1, vis) ||
        dfs(board , word, i, j-1, idx+1, vis);
        vis[i][j] = false;
        return found;
    }
   
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0, vis))
                    return true;
            }
        }
        return false;
    }
};