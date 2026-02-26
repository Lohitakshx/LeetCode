class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        return [[nums[i] for i in range(n) if mask & (1<<i)] for mask in range(1<<n)]