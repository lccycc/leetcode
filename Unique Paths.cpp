class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        vector<int> p;
        int pnt = 0;
        for (int i = 0; i<n; i++){
            p.push_back(1);
        }
        for (int i = 1; i<m; i++){
            for (int j = 1; j<n; j++){
                p[j] += p[j-1];
            }
        }
        return p[n-1];
    }
};

