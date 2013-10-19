class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> a[2];
        for (int i = 0; i<n; i++){
            a[0].push_back(0);
            a[1].push_back(0);
        }
        int t = 0;
        a[t][0] = triangle[0][0];
        for (int i = 1; i<n; i++){
            a[t^1][0] = a[t][0] + triangle[i][0];
            for (int j = 1; j<i; j++){
                a[t^1][j] = min(a[t][j] , a[t][j-1]) + triangle[i][j];
            }
            a[t^1][i] = a[t][i-1] + triangle[i][i];
            t^=1;
        }
        int res = INT_MAX;
        for (int i = 0; i<n; i++){
            res = min(res, a[t][i]);
        }
        return res;
    }
};
