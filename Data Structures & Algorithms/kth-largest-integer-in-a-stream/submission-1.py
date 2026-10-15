class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.q = []
        self.k = k
        for i in nums:
            heapq.heappush(self.q, i)
            if len(self.q) > self.k:
                heapq.heappop(self.q)
        
    def add(self, val: int) -> int:
        heapq.heappush(self.q, val)
        if len(self.q) > self.k:
            heapq.heappop(self.q)
        return self.q[0]
