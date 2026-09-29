class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans = 0
        currmax = 0
        l = 0
        r = len(height) - 1

        while l < r:
            currmax = min(height[l], height[r]) * (r - l)
            ans = max(currmax, ans)

            if height[l] > height[r]:
                r -= 1

            else:
                l += 1

        return ans
