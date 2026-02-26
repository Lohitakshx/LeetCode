class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        for num in nums:
            size = len(ans)
            for i in range(size):
                subset = ans[i].copy()
                subset.append(num)
                ans.append(subset.copy())
        return ans