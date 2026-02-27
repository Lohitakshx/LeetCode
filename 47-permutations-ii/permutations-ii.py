 
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        self.ans = set()
        self.back(nums, 0)
        return list(self.ans)
    def back(self, nums:List[int], idx:int):
        if idx == len(nums):
            self.ans.add(tuple(nums.copy()))
            return
        for i in range(idx, len(nums)):
            nums[i], nums[idx] = nums[idx], nums[i]
            self.back(nums, idx+1)
            nums[i], nums[idx] = nums[idx], nums[i]
        return