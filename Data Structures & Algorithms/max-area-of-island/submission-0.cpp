class Solution {
public:

    int dfs(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<int>>& grid, int area) {
        vis[i][j] = 1;
        area++;

        if (i + 1 < n && grid[i + 1][j] == 1 && vis[i + 1][j] != 1)
            area = dfs(i + 1, j, n, m, vis, grid, area);
        if (i - 1 >= 0 && grid[i - 1][j] == 1 && vis[i - 1][j] != 1)
            area = dfs(i - 1, j, n, m, vis, grid, area);
        if (j + 1 < m && grid[i][j + 1] == 1 && vis[i][j + 1] != 1)
            area = dfs(i, j + 1, n, m, vis, grid, area);
        if (j - 1 >= 0 && grid[i][j - 1] == 1 && vis[i][j - 1] != 1)
            area = dfs(i, j - 1, n, m, vis, grid, area);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int area = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) { 
                if (grid[i][j] == 1 && vis[i][j] != 1) {
                    area = dfs(i, j, n, m, vis, grid, area);
                    ans = max(ans, area);
                    area = 0;
                }
            }
        }
        return ans;
    }
};
