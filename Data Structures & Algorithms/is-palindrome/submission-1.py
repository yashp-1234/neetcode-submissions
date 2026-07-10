class Solution:
    def isPalindrome(self, s: str) -> bool:
        st = ""
        for i in range(len(s)):
            if 48 <= ord(s[i]) <= 57 or 65 <= ord(s[i]) <= 90 or 97 <= ord(s[i]) <= 122:
                st += s[i]

        i = 0
        for i in range(len(st)):
            if st[i].lower() != st[-i-1].lower():
                return False
        return True