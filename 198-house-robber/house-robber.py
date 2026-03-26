class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [-1] * len(nums)
        def dfs(idx):
            if idx < 0: return 0
            if dp[idx] != -1: return dp[idx]
            dp[idx] = max(dfs(idx-2) + nums[idx], dfs(idx-1))  
            return dp[idx]
        return dfs(len(nums)-1)  