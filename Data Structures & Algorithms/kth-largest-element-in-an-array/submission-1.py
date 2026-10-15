class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        q = [-num for num in nums]
        heapq.heapify(q)

        while k > 1:
            heapq.heappop(q)
            k -= 1

        return -q[0]