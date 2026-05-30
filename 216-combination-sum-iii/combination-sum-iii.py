class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        def backtrack(k, target, path, start):
            if target == 0 and k == 0:
                res.append(path.copy())
                return 
            for i in range(start, 10):
                if i > target or k<=0:
                    break
                path.append(i)
                backtrack(k-1, target-i, path, i+1)
                path.pop()
        backtrack(k, n, [], 1)
        return res