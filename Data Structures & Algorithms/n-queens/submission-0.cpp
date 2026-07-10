class Solution {
public:

    bool isSafe(int row, int j, int& n, vector<string>& board){
        for(int i=0; i<n; i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }
        for(int i=0; i<n; i++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i= 1, k = 1; row-i >=0 && j-k>=0; i++, k++){
            if(board[row-i][j-k] == 'Q'){
                return false;
            }
        }
        for(int i= 1, k = 1; row-i >=0 && j+k < n; i++, k++){
            if(board[row-i][j+k] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(isSafe(row, j, n, board)){
                board[row][j] = 'Q';
                nQueens(board, row+1, n, ans);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string dots = "";
        for(int i=0; i<n; i++){
            dots += '.';
        }
        vector<string> board(n, dots);
        vector<vector<string>> ans;
        
        nQueens(board, 0, n, ans);

        return ans;
    }
};
