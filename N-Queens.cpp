class Solution {
public:
    vector<int> row;
    vector<bool> slp, slm;
    vector<vector<string> > res;
    void dfs(int n, int k){
        if (k>=n){
            vector<string> tmp;
            for (int i = 0; i<n; i++){
                string s;
                for (int j = 0; j<row[i]; j++) s += '.';
                s += 'Q';
                for (int j = row[i]+1; j<n; j++) s += '.';
                tmp.push_back(s);
            }
            res.push_back(tmp);
            return ;
        }
        for (int i = k; i<n; i++){
            int x = row[i];
            if (slm[x-k+n] || slp[x+k] ){
                continue;
            }
            swap(row[k], row[i]);
            slm[x-k+n] = slp[x+k] = true;
            dfs(n, k+1);
            slm[x-k+n] = slp[x+k] = false;
            swap(row[k], row[i]);
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        row.clear();
        slp.clear();
        for (int i = 0; i<n+n; i++){
            slp.push_back(0);
        }
        slm = slp;
        for (int i = 0; i<n; i++){
            row.push_back(i);
        }
        res.clear();
        dfs(n, 0);
        return res;
    }
};
