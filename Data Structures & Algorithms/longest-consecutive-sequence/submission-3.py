class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
            
        mp = collections.defaultdict(int)

        for n in nums:

            if mp[n] != 0:
                continue

            mp[n] = mp[n - 1] + mp[n + 1] + 1
            mp[n - mp[n - 1]] = mp[n]
            mp[n + mp[n + 1]] = mp[n]

        return max(mp.values())