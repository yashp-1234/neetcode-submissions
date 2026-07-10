class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        // min-heap: (max-height-so-far, x, y)
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto cur = pq.top(); 
            pq.pop();

            int height = cur[0];
            int x = cur[1];
            int y = cur[2];

            if (x == n-1 && y == n-1) return height;

            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    pq.push({max(height, grid[nx][ny]), nx, ny});
                }
            }
        }

        return -1;
    }
};

