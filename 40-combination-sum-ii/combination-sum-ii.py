class Solution:
    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:
        ansSet = set()
        nums.sort()
        def dfs(idx, curr, total):
            if total == target: 
                ansSet.add(tuple(curr.copy()))
                return 
            if total>target or idx>=len(nums):
                return 
            curr.append(nums[idx])
            dfs(idx+1, curr, total+nums[idx])
            curr.pop()
            nextIdx = idx+1
            while nextIdx<len(nums) and nums[idx]==nums[nextIdx]: nextIdx+=1
            dfs(nextIdx, curr, total)
        dfs(0,[],0)
        return list(ansSet)