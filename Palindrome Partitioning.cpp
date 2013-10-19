class Solution {
public:
    vector<vector<string> > res;
    vector<string> stack;
    bool ispara(string &s, int f, int t){
        for (int i = f, j = t; i<j; i++, j--){
            if (s[i] != s[j]) return false;
        }
        return true;
    }
    void dfs(string &s, int k, int sta){
        if (k >= s.length()){
            vector<string> xs = stack;
            xs.resize(sta);
            res.push_back(xs);
            return ;
        }
        for (int i = k; i<s.size(); i++){
            if (ispara(s, k, i)){
                stack[sta] = s.substr(k, i-k+1);
                dfs(s, i+1, sta+1);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        res.clear();
        if (s.size() == 0) return res;
        stack.clear();
        stack.resize(s.size());
        dfs(s, 0, 0);
        return res;
    }
};
