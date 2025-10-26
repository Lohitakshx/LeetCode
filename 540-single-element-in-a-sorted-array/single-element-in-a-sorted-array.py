class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n=0
        for i in nums:
            n^=i
        return n