class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size()-1;
        for(int i = 0; i<n; i++){
            if(matrix[i][m] < target){
                continue;
            }
            else{
                int l = 0;
                int r = m;
                int mid = 0;
                while(l<=r){
                    mid = (l + r) / 2;
                    if(matrix[i][mid] == target){
                        return true;
                    }
                    if(matrix[i][mid] > target){
                        r = mid - 1; 
                    }
                    else{
                        l = mid + 1;
                    }
                }
                return false;
            }
        }
        return false;
    }
};