class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        def rob_range(start, end):
            dp = [-1] * len(nums)

            def dfs(i):
                if i > end:
                    return 0
                if dp[i] != -1:
                    return dp[i]

                take = nums[i] + dfs(i + 2)
                skip = dfs(i + 1)
                dp[i] = max(take, skip)
                return dp[i]

            return dfs(start)

        return max(
            rob_range(0, len(nums) - 2),  # Skip the last house
            rob_range(1, len(nums) - 1)   # Skip the first house
        )