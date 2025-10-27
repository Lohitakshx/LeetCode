class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        count = 0
        n = len(citations)
        for i in range(n - 1, -1, -1):
            if citations[i]<count+1 : return count
            count+=1
        return count