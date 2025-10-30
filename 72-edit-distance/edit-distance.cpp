class Solution {
public:
    int solve(string& word1, string& word2, int i, int j,  vector<vector<char>>& dp){
        int m = word1.size();
        int n = word2.size();
        if(i==m) return n-j;
        if(j==n) return m-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = solve(word1, word2, i+1, j+1, dp);
        int one = solve(word1, word2, i+1, j+1, dp);
        int two = solve(word1, word2, i+1, j, dp);
        int three = solve(word1, word2, i, j+1, dp); 

        return dp[i][j] = 1+min({one, two, three});
        
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<char>> dp(m , vector<char>(n, -1));
        return solve(word1, word2, 0 , 0, dp);
    }
};



 // public:
//     // int solve(string& word1, string& word2, int n, int m){
//     //     if(word[n], word)
//     // }
//     int minDistance(string word1, string word2) {
//         // solve(word1, word2, 0 , 0);
//         int n = word1.size();
//         int m = word2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
//         for(int i = 0; i<=n; i++) dp[i][0] = i;
//         for(int i = 0; i<=m; i++) dp[0][i] = i;

//         int ans = 0;
//         for(int i = 1; i<=n; i++){
//             for(int j = 1; j<=m; j++){
//                 if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
//                 else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
//             }
//         }
//         return dp[n][m];
//     }
// };

