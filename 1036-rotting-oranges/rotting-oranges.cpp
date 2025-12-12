class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<pair<int, int> , int>> q;
        int freshCount = 0;
        for(int row = 0; row < m; row++){
            for(int col = 0; col<n; col++){
                if(grid[row][col]==2){
                    q.push({{row, col}, 0});
                    vis[row][col] = 1;
                }
                else if(grid[row][col] == 1) freshCount++;
            }
        }

        int drow[] = {0, 1, 0, -1};
        int dcol[] = {-1, 0, 1, 0};

        int ans = 0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            ans = max(time, ans);
            q.pop();
            for(int i = 0 ; i<4 ; i++){
                int tempRow = row + drow[i];
                int tempCol = col + dcol[i];
                if(tempRow >= 0 && tempRow<m && tempCol >=0 && tempCol < n && grid[tempRow][tempCol] == 1 && vis[tempRow][tempCol]!=1){
                    q.push({{tempRow, tempCol}, time+1});
                    freshCount--;
                    vis[tempRow][tempCol] = 1;
                }
            }
        }
        return freshCount ? -1 : ans;
    }
};