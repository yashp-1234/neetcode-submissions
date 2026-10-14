class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        cnt1 = [0] * 26
        cnt2 = [0] * 26

        # Count s1 and the first window of s2
        for i in range(len(s1)):
            cnt1[ord(s1[i]) - ord('a')] += 1
            cnt2[ord(s2[i]) - ord('a')] += 1

        if cnt1 == cnt2:
            return True

        l = 0

        # Slide the window
        for r in range(len(s1), len(s2)):
            # Add the new right character
            cnt2[ord(s2[r]) - ord('a')] += 1

            # Remove the old left character
            cnt2[ord(s2[l]) - ord('a')] -= 1
            l += 1

            if cnt1 == cnt2:
                return True

        return False