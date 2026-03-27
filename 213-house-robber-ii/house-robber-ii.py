class Solution:
    def rob(self, nums):
        n = len(nums)
        
        if n == 1:
            return nums[0]
        
        def helper(start, end):
            dp = [0] * n
            dp[start] = nums[start]
            
            for i in range(start + 1, end + 1):
                take = nums[i]
                if i - 2 >= start:
                    take += dp[i - 2]
                
                skip = dp[i - 1]
                dp[i] = max(take, skip)
            
            return dp[end]
        
        return max(
            helper(0, n - 2),  # exclude last
            helper(1, n - 1)   # exclude first
        )