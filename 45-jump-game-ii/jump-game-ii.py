class Solution:
    def jump(self, nums: List[int]) -> int:
        far = near = ans = 0
        while far < len(nums)-1:
            temp = 0
            for i in range(near, far+1):
                temp = max(temp, nums[i]+i)
            near = far+1
            far = temp
            ans+=1
        return ans