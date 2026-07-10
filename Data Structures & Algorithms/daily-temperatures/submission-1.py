class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = [0] * len(temperatures)
        st = []
        
        for i in range(len(temperatures)):
            while len(st) > 0 and st[-1][1] < temperatures[i]:
                idx, temp = st.pop()
                ans[idx] = i - idx
            
            st.append((i, temperatures[i]))
        
        return ans