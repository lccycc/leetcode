class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int res = 0;
        vector<int> l, r, h;
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        for (int i = 0; i<m; i++){
            h.push_back(0);
        }
        l = r = h;
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                if (matrix[i][j] == '0'){
                    h[j] = 0;
                }else{
                    h[j]++;
                }
            }
            for (int j = 0; j<m; j++){
                int p = j-1;
                while (p>=0){
                    if (h[p] < h[j]) break;
                    p = l[p];
                }
                l[j] = p;
            }
            for (int j = m-1; j>=0; j--){
                int p = j+1;
                while (p<m){
                    if (h[p] < h[j]) break;
                    p = r[p];
                }
                r[j] = p;
            }
            for (int j = 0; j<m; j++){
                res = max(res, h[j] * (r[j]-l[j]-1));
            }
        }
        return res;
    }
};


