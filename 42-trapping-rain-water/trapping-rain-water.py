class Solution:
    def trap(self, nums: List[int]) -> int:
        l = 0
        r = len(nums)-1
        rm = nums[r]
        lm = nums[l]
        water = 0
        while l<r:
            if(rm<lm):
                r-=1
                rm = max(rm, nums[r])
                water += rm-nums[r]
            else:
                l+=1
                lm = max(lm, nums[l])
                water += lm-nums[l]
        return water