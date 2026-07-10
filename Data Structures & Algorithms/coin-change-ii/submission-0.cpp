class Solution {
private:
    int dfs(int i, int remaining, vector<int>& coins, vector<vector<int>>& dp) {
        if (remaining == 0) return 1;
        if (remaining < 0) return 0;
        if (i == coins.size()) return 0;

        if (dp[i][remaining] != -1)
            return dp[i][remaining];

        int take = dfs(i, remaining - coins[i], coins, dp);
        int skip = dfs(i + 1, remaining, coins, dp);

        return dp[i][remaining] = take + skip;
    }

public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return dfs(0, amount, coins, dp);
    }
};

