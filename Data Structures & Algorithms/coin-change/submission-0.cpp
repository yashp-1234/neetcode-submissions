class Solution {
public:
    int helper(int rem, vector<int>& dp, vector<int>& coins) {
        if (rem == 0) return 0;          
        if (rem < 0) return 1e9;         
        if (dp[rem] != -1) return dp[rem];

        int minCoins = 1e9;
        for (int coin : coins) {
            int res = helper(rem - coin, dp, coins);
            if (res != 1e9) {
                minCoins = min(minCoins, 1 + res);
            }
        }

        return dp[rem] = minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = helper(amount, dp, coins);
        return (ans == 1e9 ? -1 : ans);
    }
};

