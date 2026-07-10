class Solution {
public:
    int makedp(int i, vector<int>& dp){
        if(i == 0 || i == 1){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        dp[i] = makedp(i-1, dp) + makedp(i-2, dp);
        return dp[i];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        int ans = makedp(n, dp);
        return ans;
    }
};