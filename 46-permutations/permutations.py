class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        for p in permutations(nums):
            ans.append(p)
        return ans