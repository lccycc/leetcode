class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        vector<int> p, l, r;
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        p.resize(m);
        l.resize(m);
        r.resize(m);
        int ans = 0;
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++) if (matrix[i][j] == '1') p[j]++; else p[j] = 0;
            for (int j = 0; j<m; j++){
                l[j] = j-1;
                while (l[j] >= 0 && p[l[j]] >= p[j]){
                    l[j] = l[l[j]];
                }
            }
            for (int j = m-1; j>=0; j--){
                r[j] = j+1;
                while (r[j] <m && p[r[j]] >= p[j]){
                    r[j] = r[r[j]];
                }
            }
            for (int j = 0; j<m; j++) ans = max(ans, p[j] * (r[j] - l[j] - 1));
        }
        return ans;
    }
};
