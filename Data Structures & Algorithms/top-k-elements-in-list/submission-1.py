class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mymap = dict()
        for i in nums:
            if i not in mymap:
                mymap[i] = 1
            mymap[i] += 1

        pq = []
        for key, val in mymap.items():
            heapq.heappush(pq, [val, key])
            if len(pq) > k:
                heapq.heappop(pq)
        
        ans = []
        for freq, num in pq:
            ans.append(num)

        return ans