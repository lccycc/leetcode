class Solution {
public:
/* save match[i][j]: s[i->j] is one of the dictionary */
    vector<set<int> > match;
    vector<string> res;
    vector<int> cutpoint;
    vector<bool> f;
    void dfs(int ncut, string &s){
        int cpnt = cutpoint[ncut-1];
        if (cpnt == s.size()){
            string tmp = s.substr(0, cutpoint[1]);
            for (int i = 1; i<ncut-1; i++){
                tmp = tmp + " " + s.substr(cutpoint[i], cutpoint[i+1]-cutpoint[i]);
            }
            res.push_back(tmp);
            return;
        }
        for (int nxt : match[cpnt]){
            cutpoint[ncut] = nxt;
            dfs(ncut+1, s);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        match.clear();
        for (int i = 0; i<n; i++){
            match.push_back(set<int>());
            for (int j = i+1; j<=n; j++){
                if (dict.find(s.substr(i, j-i))!=dict.end()){
                    match.back().insert(j);
                }
            }
        }
        res.clear();
        cutpoint.resize(n+1);
        cutpoint[0] = 0;
        f.resize(n+1);
        f[n] = 1;
        for (int i = n-1; i>=0; i--){
            f[i] = 0;
            auto tmp = match[i];
            for (int nxt : tmp) {
                f[i] = f[i] || f[nxt];
                if (!f[nxt]){
                    match[i].erase(nxt);
                }
            }
        }
        dfs(1, s);
        return res;
    }
};
