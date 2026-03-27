class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1 : return nums[0]
        def dfs(idx, arr, dp):
            if idx < 0 : return 0
            if dp[idx] != -1 : return dp[idx]
            dp[idx] = max(dfs(idx-2, arr, dp) + arr[idx] , dfs(idx-1, arr, dp))
            return dp[idx]
        return max(dfs(len(nums[1:])-1,nums[1:], [-1]*len(nums[1:])), dfs(len(nums[:-1])- 1, nums[:-1], [-1] * len(nums[:-1])))
        