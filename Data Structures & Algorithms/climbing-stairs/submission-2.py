class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [-1]*(n+1)
        def dfs(n):
            if dp[n] != -1:
                return dp[n]
            if n == 0:
                return 1
            if n == 1:
                return 1

            if n > 1:
                left = dfs(n-1)
                right = dfs(n-2)

            dp[n] = (left + right)
            return dp[n]
    
        return dfs(n)