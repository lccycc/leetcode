class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        vector<vector<int> > &a = obstacleGrid;
        int n = a.size();
        if (n == 0) return 0;
        int m = a[0].size();
        if (m == 0) return 0;
        if (a[0][0] == 1) return 0;
        a[0][0] = 1;
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++) if (i||j){
                if (a[i][j] == 1){
                    a[i][j] = 0;
                }else{
                    if (i) a[i][j] += a[i-1][j];
                    if (j) a[i][j] += a[i][j-1];
                }
            }
        }
        return a[n-1][m-1];
    }
};
