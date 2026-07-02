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
            else:
                if not arr:
                    return False
                if pairs[i] == arr[-1]:
                    arr.pop()
                else:
                    return False
        return not arr