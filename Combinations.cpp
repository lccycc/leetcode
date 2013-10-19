class Solution {
public:
    vector<vector<int> > res;
    vector<int> s;
    void dfs(int p, int n, int k, int kr){
        if (k >= kr){
            res.push_back(s);
            return ;
        }
        for (s[k] = p; s[k]+kr-k<=n+1; s[k]++){
            dfs(s[k]+1, n, k+1, kr);
        }
    }
    vector<vector<int> > combine(int n, int k) {
        res.clear();
        if (n == 0 || k == 0) return res;
        s.resize(k);
        dfs(1, n, 0, k);
        return res;
    }
};


