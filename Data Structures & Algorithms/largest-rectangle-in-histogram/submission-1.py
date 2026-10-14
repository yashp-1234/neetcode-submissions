class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        st = []
        ans = 0
        for i, h in enumerate(heights):
            start = i
            while st and st[-1][1] > h:
                idx, hei = st.pop()
                ans = max(ans, hei * (i - idx))
                start = idx
            st.append((start, h))

        for i, h in st:
            ans = max(ans, h * (len(heights) - i))

        return ans
