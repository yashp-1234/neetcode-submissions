class Solution {
public:
    vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<int>> ans;

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> isPac(rows, vector<bool> (cols, false));
        vector<vector<bool>> isAtl(rows, vector<bool> (cols, false));

        queue<pair<int, int>> pacQueue;
        queue<pair<int, int>> atlQueue;

        for(int i=0; i<cols; i++){
            pacQueue.push({0, i});
            atlQueue.push({rows-1, i});
        }

        for(int i=0; i<rows; i++){
            pacQueue.push({i, 0});
            atlQueue.push({i, cols-1});
        }

        bfs(pacQueue, isPac, heights);
        bfs(atlQueue, isAtl, heights);

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(isPac[i][j] && isAtl[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

private:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        while(!q.empty()){

            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            ocean[r][c] = true;

            for(int i=0; i<4; i++){
                int newr = r + directions[i].first;
                int newc = c + directions[i].second;

                if (newr >= 0 && newr < heights.size() && newc >= 0 &&
                    newc < heights[0].size() && !ocean[newr][newc] &&
                    heights[newr][newc] >= heights[r][c]) {
                    q.push({newr, newc});
                }
            }
        }
    }
};
