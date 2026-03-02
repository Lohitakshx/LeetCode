class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        subset = []
        nums.sort()
        def back(idx):
            ans.append(subset.copy())
            for i in range(idx, len(nums)):
                if i!=idx and nums[i]==nums[i-1]: continue
                subset.append(nums[i])
                back(i+1)
                subset.pop()
        back(0)
        return ans