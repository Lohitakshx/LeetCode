class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = prices[0];
        vector<int> dp(prices.size(), 0);
        int ans = 0;
        for(int i = 0; i<prices.size(); i++){
            if(prices[i]>minn){
                int temp = prices[i]-minn;
                ans = max(ans,temp);
            }
            minn = min(minn, prices[i]);
        }
        return ans;
    }
};