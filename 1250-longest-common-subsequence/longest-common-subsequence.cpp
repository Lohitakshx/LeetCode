class Solution {
public:
    // int loki(int n , int m, string text1, string text2){
    //     if(n==-1||m==-1) return 0;
    //     if(text1[n]==text2[m]) return 1 + loki(n-1, m-1, text1, text2);
    //     return max(loki(n-1, m, text1, text2), loki(n, m-1, text1, text2));

    // }
    // int loki1(int )
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(text1[i]==text2[j]) dp[i+1][j+1]=1+dp[i][j];
                else dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
            }

        }
        // for(auto i: dp){

        // }
        return dp[n][m];
    }
};