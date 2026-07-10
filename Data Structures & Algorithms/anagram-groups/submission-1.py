from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mymap = {}  # key: tuple(counts) -> list of indices
        for i in range(len(strs)):
            bp = [0] * 26
            for j in range(len(strs[i])):
                bp[ord(strs[i][j]) - ord('a')] += 1
            key = tuple(bp)
            if key not in mymap:
                mymap[key] = []
            mymap[key].append(i)
        
        ans = []
        for key, val in mymap.items():
            group = []
            for idx in val:
                group.append(strs[idx])
            ans.append(group)

        return ans