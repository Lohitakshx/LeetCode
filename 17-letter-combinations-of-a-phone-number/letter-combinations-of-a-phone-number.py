class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        ans = [""]
        digitToChar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }
        for d in digits:
            temp = []
            for curStr in ans:
                for c in digitToChar[d]:
                    temp.append(curStr + c)
            ans = temp
        return ans