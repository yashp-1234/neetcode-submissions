class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        st = []
        ans = [0] * len(temperatures)

        for i in range(len(temperatures)):
            while len(st) > 0 and st[-1][1] < temperatures[i]:
                idx, temp = st.pop()
                ans[idx] = i - idx

            st.append([i, temperatures[i]])

        return ans
        