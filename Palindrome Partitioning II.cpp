class Solution {
public:
    int minCut(string s) {
        if (s.size() == 0) return 0;
        vector<vector<int> > f;
        f.resize(s.size());
        for (int i = 0; i<s.size(); i++){
            for (int len = 0; i-len>=0 && i+len<s.size() && s[i-len] == s[i+len]; len++){
                f[i-len].push_back(i+len+1);
            }
            for (int len = 0; i-len>=0 && i+len+1<s.size() && s[i-len] == s[i+len+1]; len++){
                f[i-len].push_back(i+len+2);
            }
        }
        vector<int> a;
        a.resize(s.size()+1);
        for (int i = 0; i<=s.size(); i++) a[i] = i;
        for (int i = 0; i<s.size(); i++){
            for (int nex : f[i]){
                a[nex] = min(a[nex], a[i]+1);
            }
        }
        return a[s.size()]-1;
    }
};
