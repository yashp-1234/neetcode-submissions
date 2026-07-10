class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for i in range(len(s)):
            if s[i] in '([{':
                st.append(s[i])
            elif s[i] == ')':
                if st and st[-1] == '(':
                    st.pop()
                else:
                    return False
            elif s[i] == ']':
                if st and st[-1] == '[':
                    st.pop()
                else:
                    return False
            elif s[i] == '}':
                if st and st[-1] == '{':
                    st.pop()
                else:
                    return False

        return len(st) == 0