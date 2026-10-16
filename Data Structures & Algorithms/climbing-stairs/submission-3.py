class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [-1] * (n + 1)
        dp[0] = 1

        if n >= 1:
            dp[1] = 1

        for i in range(2, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]

        # dp = [-1]*(n+1)
        # def dfs(n):
        #     if dp[n] != -1:
        #         return dp[n]
        #     if n == 0:
        #         return 1
        #     if n == 1:
        #         return 1

        #     if n > 1:
        #         left = dfs(n-1)
        #         right = dfs(n-2)

        #     dp[n] = (left + right)
        #     return dp[n]
    
        # return dfs(n)