class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        for i in range(len(nums)):
            size = len(ans)
            for j in range(size):
                subset = ans[j].copy()
                subset.append(nums[i])
                ans.append(subset)
        return ans