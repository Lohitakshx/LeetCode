class Solution:

    def partition(self, s: str) -> List[List[str]]:
        ans = []
        path = []
        def isPalindrome(l, r):
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True
        def dfs(idx):
            if idx == len(s):
                ans.append(path.copy())
                return 
            for end in range(idx, len(s)):
                if isPalindrome(idx, end):
                    path.append(s[idx:end+1])
                    dfs(end+1)
                    path.pop()
        dfs(0)
        return ans 
