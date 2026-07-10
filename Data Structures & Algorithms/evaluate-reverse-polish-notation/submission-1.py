class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []

        for token in tokens:
            if token in {"+", "-", "*", "/"}:
                a = int(st.pop())
                b = int(st.pop())

                if token == "+":
                    st.append(b + a)
                elif token == "-":
                    st.append(b - a)
                elif token == "*":
                    st.append(b * a)
                else:
                    st.append(int(b / a))  # truncates toward zero
            else:
                st.append(int(token))

        return st[0]