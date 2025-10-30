class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        vector<int> dp(amount+1, amount+1); //amount+1 is considered as infinity
        dp[0] = 0;
        for(int i = 1; i<=amount; i++){
            for(auto coin : coins){
                if(i-coin >= 0){
                    dp[i] = min(1+dp[i-coin], dp[i]);
                }
            }
        }
        return (dp[amount]>amount) ? -1: dp[amount];
    }
};

