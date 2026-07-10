class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    vis[i][j] = 0;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0 and vis[i][j] == 0){
                    vector<int> zeros (n, 0);
                    matrix[i] = zeros;

                    for(int k=0; k<m; k++){
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
};