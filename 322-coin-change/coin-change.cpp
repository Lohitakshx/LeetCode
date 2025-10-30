class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        if(dp[amount]!=-2) return dp[amount];
        int minn = INT_MAX;
        for(int i = 0; i<coins.size(); i++){
            int res = solve(coins, amount- coins[i], dp);
            if(res>= 0 && res<minn) minn = res + 1;
        }
        return dp[amount] = (minn == INT_MAX) ? -1: minn;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -2);
        return solve(coins, amount, dp);
    }
};