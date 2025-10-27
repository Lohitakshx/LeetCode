class Solution:
    def hIndex(self, citations: List[int]) -> int:
        minn = 0
        maxx = len(citations)
        ans = 0
        while(minn<=maxx):
            avgg = (minn + maxx)//2
            count = 0
            for i in citations:
                if i >= avgg: count+=1
            if count >= avgg : 
                ans = avgg
                minn = avgg+1
            else : 
                maxx = avgg-1
        return ans