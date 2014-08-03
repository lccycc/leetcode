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
/* no recursive
class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> xmy, xpy, sp;
        int sum = 0;
        stack<int> pos;
        xmy.resize(n+n+1);
        xpy.resize(n+n+1);
        sp.resize(n);
        pos.push(0);
        int x, y;
        while (pos.size()){
            x = pos.size()-1, y = pos.top();
            if (y){
                sp[y-1] = xpy[x+y-1] = xmy[n-x+y-1] = false;
            }
            pos.pop();
            if (x>=n){
                sum++;
                continue;
            }
            while (y<n && (sp[y] || xpy[x+y] || xmy[n-x+y])) y++;
            if (y>=n){
                continue;
            }
            pos.push(y+1);
            sp[y] = xpy[x+y] = xmy[n-x+y] = true;
            pos.push(0);
        }
        return sum;
    }
};
*/
