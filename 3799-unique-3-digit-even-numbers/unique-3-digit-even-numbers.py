class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        freq = Counter(digits)
        ans = 0
        for num in range(100, 1000, 2):
            ans += Counter(map(int, str(num))) <= freq
        return ans