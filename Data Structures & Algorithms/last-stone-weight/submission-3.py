class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if len(stones) == 1:
            return stones[0]
        q = [-stone for stone in stones]
        heapq.heapify(q)

        while len(q) != 1:
            st1 = heapq.heappop(q)
            st2 = heapq.heappop(q)
            heapq.heappush(q, st1 - st2)

        return -q[0]