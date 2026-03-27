class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1 : return nums[0]
        def helper(start, end) -> int:
            prev1 , prev2 = 0, 0
            for i in range(start, end+1):
                curr = max(prev1, prev2 + nums[i])
                prev2 = prev1
                prev1 = curr
            return prev1
        return max(
            helper(0, len(nums)-2), helper(1, len(nums) - 1)
        )

    