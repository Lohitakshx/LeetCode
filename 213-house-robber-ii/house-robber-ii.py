class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1 : return nums[0]
        return max(self.helper(nums[1:]), self.helper(nums[:-1]))

    def helper(self, nums: List[int]) -> int:
        prev1 , prev2 = 0, 0
        for num in nums:
            curr = max(prev1, prev2 + num)
            prev2 = prev1
            prev1 = curr
        return prev1