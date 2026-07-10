class Solution {
public:
    int dfs (int i, int j, int &m, int &n, vector<vector<int>> &dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i == m || j == n){
            return 0;
        }

        int down = dfs(i+1, j, m, n, dp);

        int right = dfs(i, j+1, m, n, dp);

        dp[i][j] = down + right;

        return dp[i][j];

    }
    int uniquePaths(int m, int n) {
        int ans = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        ans = dfs(0, 0, m, n, dp);
        return ans;
    }
};