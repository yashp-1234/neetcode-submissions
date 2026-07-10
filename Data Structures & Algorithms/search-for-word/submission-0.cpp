class Solution {
public:
    bool searchWord(int i, int j, int n, int m, int index, const string& word, vector<vector<char>>& board) {
        if(i < 0 || i >= m || j < 0 || j >= n) return false;   // out of bounds
        if(board[i][j] != word[index]) return false;           // mismatch
        if(index == word.size() - 1) return true;              // last char matched

        char temp = board[i][j];
        board[i][j] = '-'; // mark visited

        bool ansExist =
            searchWord(i+1, j, n, m, index+1, word, board) ||
            searchWord(i-1, j, n, m, index+1, word, board) ||
            searchWord(i, j+1, n, m, index+1, word, board) ||
            searchWord(i, j-1, n, m, index+1, word, board);

        board[i][j] = temp; 
        return ansExist;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){  // match starting letter
                    if(searchWord(i, j, n, m, 0, word, board))
                        return true;
                }
            }
        }
        return false;
    }
};

