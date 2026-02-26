class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        n = len(nums)
        for mask in range(1<<n):
            ans.append([nums[i] for i in range(n) if mask & (1<<i)])
        return ans