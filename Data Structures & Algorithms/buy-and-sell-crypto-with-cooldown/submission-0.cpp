class Solution {
// buy = 1 (can buy)
// buy = 0 (cannot buy)
private:
    int dfs(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i >= prices.size()){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;

        if(buy){
            profit = max (-prices[i] + dfs(i+1, 0, prices, dp), dfs(i+1, 1, prices, dp));
        }
        else{
            profit = max (prices[i] + dfs(i+2, 1, prices, dp), dfs(i+1, 0, prices, dp));
        }

        dp[i][buy] = profit;
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        ans = dfs(0, 1, prices, dp);
        return ans;
    }
};
