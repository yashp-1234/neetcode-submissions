class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1

        lmax = 0
        rmax = 0

        ans = 0

        while l < r:
            if height[l] < height[r]:
                if lmax < height[l]:
                    lmax = height[l]
                else:
                    ans += (lmax - height[l])
                l += 1
            else:
                if rmax < height[r]:
                    rmax = height[r]
                else:
                    ans += (rmax - height[r])
                r -= 1

        return ans
