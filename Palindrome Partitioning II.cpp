class Solution {
public:
    bool ispara(string &s, int l, int r){
        for (;l<r; l++, r--){
            if (s[l] != s[r]) return false;
        }
        return true;
    }
    int minCut(string s) {
        if (s.size() == 0) return 0;
        vector<int> p;
        vector<vector<int> > f;
        f.resize(s.size());
        for (int i = 0; i<s.size(); i++){
            int j = 0;
            while (i-j>=0 && i+j<s.size() && s[i-j] == s[i+j]){
                f[i+j].push_back(i-j);
                j++;
            }
            j = 0;
            while (i-j>=0 && i+j+1<s.size() && s[i-j] == s[i+j+1]){
                f[i+j+1].push_back(i-j);
                j++;
            }
        }
        p.push_back(0);
        for (int i = 0; i<s.size(); i++){
            int x = s.size();
            for (int kj = 0; kj<f[i].size(); kj++){
                int j = f[i][kj];
                x = min(x, p[j]+1);
            }
            p.push_back(x);
        }
        return p.back()-1;
    }
};


