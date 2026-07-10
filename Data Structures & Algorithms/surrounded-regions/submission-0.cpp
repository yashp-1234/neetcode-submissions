class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
private:
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& vis, vector<vector<char>>& board){
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            vis[r][c] = 1;
            for(int i=0; i<4; i++){
                int newr = r + dir[i].first;
                int newc = c + dir[i].second;

                if(newr>=0 && newr<board.size() && newc>=0 && newc<board[0].size() && board[newr][newc] == 'O' && vis[newr][newc] != 1){
                    q.push({newr, newc});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            if(board[0][i] == 'O'){
                q.push({0, i});
            }
            if(board[m-1][i] == 'O'){
                q.push({m-1, i});
            }
        }

        for(int i=0; i<m; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
            }
            if(board[i][n-1] == 'O'){
                q.push({i, n-1});
            }
        }

        bfs(q, vis, board);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && vis[i][j] != 1){
                    board[i][j] = 'X';
                }
            }
        }
    }
};