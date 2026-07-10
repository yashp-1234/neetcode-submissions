class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++){
            int j = i+1;

            while(j<n){
                swap(matrix[i][j], matrix[j][i]);
                j++;
            }
        }

        for(int i=0; i<n; i++){
            vector<int> row;
            row = matrix[i];
            reverse(row.begin(), row.end());
            matrix[i] = row;
        }
    }
};