class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> f, g;
        f.resize(m+1);
        g.resize(m+1);
        for (int i = 0; i<=m; i++) f[i] = i;
        /* f[i][j] = f[i-1][j]+1, f[i][j-1]+1, f[i-1][j-1] if match */
        for (int i = 1; i<=n; i++){
            g[0] = f[0]+1;
            for (int j = 1; j<=m; j++){
                g[j] = min(f[j], g[j-1])+1;
                g[j] = min(g[j], f[j-1]+(word1[i-1] != word2[j-1]));
            }
            f.swap(g);
        }
        return f[m];
    }
};
