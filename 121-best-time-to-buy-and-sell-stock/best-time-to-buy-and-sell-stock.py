class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minn = prices[0]
        dp = [0]*len(prices)
        ans = 0
        for i in range(len(prices)):
            if prices[i]>minn:
                ans = max(ans, prices[i] - minn)
            minn= min(minn, prices[i])
        return ans