class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for i in nums:
            count[i] = 1 + count.get(i,0)
        minHeap = []
        for num, freq in count.items():
            heapq.heappush(minHeap, [freq,num])
            if len(minHeap)>k: heapq.heappop(minHeap)
        res = []
        while minHeap:
            res.append(heapq.heappop(minHeap)[1])
        return res