class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        stack = []
        def solve(openN, closeN):
            if openN == closeN == n :
                ans.append("".join(stack))
                return 
            if openN < n:
                stack.append('(')
                solve(openN+1, closeN)
                stack.pop()
            if closeN < openN:
                stack.append(')')
                solve(openN, closeN+1)
                stack.pop()
        solve(0,0)
        return ans
