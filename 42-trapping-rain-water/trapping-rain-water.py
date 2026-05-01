class Solution:
    def trap(self, height: List[int]) -> int:
        left_max = height[0]
        right_max = height[len(height) - 1]
        l, r = 0, len(height) - 1 
        ans = 0
        while l<r:
            if left_max <= right_max:
                l+=1
                left_max = max(left_max, height[l])
                ans+=(left_max - height[l])
            else :
                r-=1
                right_max = max(right_max, height[r])
                ans+=(right_max - height[r])
        return ans
