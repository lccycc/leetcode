class Solution {
public:
    vector<vector<string> > res;
    vector<vector<int> > f;
    vector<string> tmp;
    void dfs(int k, string &s){
        if (k == s.size()){
            res.push_back(tmp);
            return ;
        }
        for (int x : f[k]){
            tmp.push_back(s.substr(k, x-k));
            dfs(x, s);
            tmp.erase(tmp.end()-1);
        }
    }
    vector<vector<string>> partition(string s) {
        res.clear();    
        f.clear();
        int n = s.size();
        f.resize(n+1);
        for (int i = 0; i<n; i++){
            for (int len = 0; i-len>=0 && i+len<n && s[i-len] == s[i+len]; len++){
                f[i-len].push_back(i+len+1);
            }
            for (int len = 0; i-len>=0 && i+len+1<n && s[i-len] == s[i+len+1]; len++){
                f[i-len].push_back(i+len+2);
            }
        }
        tmp.clear();
        dfs(0, s);
        return res;
    }
};
