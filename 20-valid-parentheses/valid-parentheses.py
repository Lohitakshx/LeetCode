class Solution:
    def isValid(self, s: str) -> bool:
        arr = []
        pairs = {
            ')' : '(',
            '}' : '{',
            ']' : '['
        }
        for i in s:
            if i in '({[': 
                arr.append(i)
            elif arr and pairs[i] == arr[-1]:
                arr.pop()
            else:
                return False
        return not arr