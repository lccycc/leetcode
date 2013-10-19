class Solution {
public:
    vector<string> res;
    int c[4];
    void dfs(string &s, int k, int len, int deta, int cp){
        if (cp >=4 ){
            if (k < s.size() || len != 0) return ;
            char tmp[20];
            sprintf(tmp, "%d.%d.%d.%d", c[0], c[1], c[2], c[3]);
            res.push_back(string(tmp));
            return ;
        }
        if (k >= s.length()) return ;

        deta = deta * 10 + s[k]-'0';
        if (deta >= 256) return ;

        c[cp] = deta;
        dfs(s, k+1, 0, 0, cp+1);

        if (len == 0 && s[k] == '0') return ;
        dfs(s, k+1, len+1, deta, cp);

    }
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        dfs(s, 0, 0, 0, 0);
        return res;
    }
};
