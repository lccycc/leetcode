class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (!n) return ;
        int m = matrix[0].size();
        if (!m) return ;
        bool row0 = false, col0 = false;
        for (int j = 0; j<m; j++) row0 = row0 || (matrix[0][j] == 0);
        for (int i = 0; i<n; i++) col0 = col0 || (matrix[i][0] == 0);
        for (int i = 1; i<n; i++){
            for (int j = 1; j<m; j++){
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = 1; i<n; i++){
            for (int j = 1; j<m; j++){
                if (matrix[i][0] ==0 ||  matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (row0){
            for (int j = 0; j<m; j++) matrix[0][j] = 0;
        }
        if (col0){
            for (int i = 0; i<n; i++) matrix[i][0] = 0;
        }
    }
};
