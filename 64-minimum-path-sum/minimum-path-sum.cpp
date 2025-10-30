class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = grid[0][0];
        for(int j = 1; j<n; j++) dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i = 1; i<m; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
       
        for(int i = 1; i<m; i++){
            for(int j = 1; j< n ; j++){
                int right = dp[i-1][j];
                int down = dp[i][j-1];

                dp[i][j] = grid[i][j] + min(right, down);
            }
        }
        return dp[m-1][n-1];
    }
};




// class Solution {
// public:
//     int solve(vector<vector<int>>& grid,int i, int j,  vector<vector<int>>& dp){
//         int m = grid.size();
//         int n = grid[0].size();
//         if(i==m-1 && j==n-1) return grid[i][j];
//         if (i >= m || j >= n) return INT_MAX;
//         if(dp[i][j]!= -1) return dp[i][j];
//         int right = solve(grid, i+1, j, dp);
//         int down = solve(grid, i, j+1, dp);
//         dp[i][j] = grid[i][j] + min(right, down);
//         return dp[i][j];
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return solve(grid, 0, 0, dp);
//     }
// };