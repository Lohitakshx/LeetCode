class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = -prices[0];
        int buy2 = -prices[0];
        int sell1 = 0;
        int sell2 = 0;
        for(int i = 0; i<prices.size(); i++){
            int temp = prices[i];
            buy1 = max(buy1, -temp);
            sell1 = max(sell1, buy1 + temp);
            buy2 = max(buy2, sell1-temp);
            sell2 = max(sell2, buy2 + temp);
        }
        return sell2;
    }
};