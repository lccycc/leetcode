class Solution {
public:
    vector<bool> slm, srm;
    vector<int> per;
    int tot;
    void dfs(int k, int n){
        if (k>=n){
            tot++;
            return ;
        }
        for (int i = k; i<n; i++){
            int x = per[i];
            if (slm[k-x+n] || srm[k+x]) continue;
            swap(per[i], per[k]);
            slm[k-x+n] = srm[k+x] = true;
            dfs(k+1, n);
            slm[k-x+n] = srm[k+x] = false;
            swap(per[i], per[k]);
        }
    }
    int totalNQueens(int n) {
        tot = 0;
        if (n == 0) return tot;
        slm.clear();
        for (int i = 0 ; i<n+n; i++){
            slm.push_back(0);
        }
        srm = slm;
        per.clear();
        for (int i = 0; i <n; i++){
            per.push_back(i);
        }
        dfs(0, n);
        return tot;
    }
};

