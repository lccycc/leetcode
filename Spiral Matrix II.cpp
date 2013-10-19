class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res;
        if (n == 0) return res;
        res.resize(n);
        for (int i = 0; i<n; i++) res[i].resize(n);
        int cnt = 1;
        int x = 0, y = 0;
        while (n>=2){
            for (int i = 0; i<n-1; i++){
                res[x][y+i] = cnt++;
            }
            for (int i = 0; i<n-1; i++){
                res[x+i][y+n-1] = cnt++;
            }
            for (int i = n-1; i>0; i--){
                res[x+n-1][y+i] = cnt++;
            }
            for (int i = n-1; i>0; i--){
                res[x+i][y] = cnt++;
            }
            x++, y++, n-=2;
        }
        if (n){
            res[x][y] = cnt++;
        }
        return res;
    }
};

