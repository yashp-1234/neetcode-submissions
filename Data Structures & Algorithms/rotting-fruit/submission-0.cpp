class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int countFresh = 0;
        int ans = 0;

        queue<pair<int, int>> q;

        // Collect rotten oranges and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    countFresh++;
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // BFS
        while (!q.empty() && countFresh > 0) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (auto& d : dirs) {
                    int r = row + d[0];
                    int c = col + d[1];

                    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1) {
                        continue;
                    }

                    grid[r][c] = 2;
                    countFresh--;
                    q.push({r, c});
                }
            }
            ans++;
        }

        return (countFresh == 0) ? ans : -1;
    }
};
