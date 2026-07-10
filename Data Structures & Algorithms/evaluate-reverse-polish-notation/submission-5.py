class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        ans = 0

        for i in tokens:
            if i == '+':
                ans = st[-2] + st[-1]
                st.pop()
                st.pop()
                st.append(ans)

            elif i == '-':
                ans = st[-2] - st[-1]
                st.pop()
                st.pop()
                st.append(ans)

            elif i == '*':
                ans = st[-2] * st[-1]
                st.pop()
                st.pop()
                st.append(ans)

            elif i == '/':
                ans = int(st[-2] / st[-1])
                st.pop()
                st.pop()
                st.append(ans)

            else:
                st.append(int(i))

        return st[0]