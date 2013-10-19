class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> p[2];
        for (int i = 0; i<=m; i++){
            p[0].push_back(i);
            p[1].push_back(0);
        }
        int pnt = 0;
        for (int i = 1; i<=n; i++){
            p[pnt^1][0] = i;
            for (int j = 1; j<=m; j++){
                p[pnt^1][j] = min(p[pnt][j], p[pnt^1][j-1])+1;
                p[pnt^1][j] = min(p[pnt^1][j],
                            p[pnt][j-1] + (word1[i-1]!=word2[j-1]));
            }
            pnt^=1;
        }
        return p[pnt][m];
    }
};


