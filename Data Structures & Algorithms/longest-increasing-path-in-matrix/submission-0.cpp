class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        int m = matrix.size();
        int n = matrix[0].size();
        int best = 1;  

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        for (auto& d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                matrix[ni][nj] > matrix[i][j]) {
                best = max(best, 1 + helper(ni, nj, matrix, dp));
            }
        }

        return dp[i][j] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, helper(i, j, matrix, dp));
            }
        }

        return ans;
    }
};

