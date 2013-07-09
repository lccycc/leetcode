class Solution {
    bool isp(string s){
        int l = 0, r = s.size()-1;
        while (l<r){
            if (s[l++]!=s[r--]){
                return false;
            }
        }
        return true;
    }
public:
    int minCut(string s) {
        vector<int> d;
        vector<pair<int, int>> p;
        int n = s.size();
        for (int i =0; i<n; i++){
            int l = i, r = i;
            while (l>=0 && r<n && s[l] == s[r]){
                p.push_back(make_pair(l, r));
                l--, r++;
            }
        }
        for (int i = 1; i<n; i++){
            int l = i-1, r = i;
            while (l>=0 && r<n && s[l] == s[r]){
                p.push_back(make_pair(l, r));
                l--, r++;
            }
        }
        for (int i = 0; i<=n; i++){
            d.push_back(n+1);X
        }
        sort(p.begin(), p.end());
        d[0] = 0;
        for (unsigned k = 0; k<p.size(); k++){
            int i = p[k].first, j = p[k].second;

            if (d[j+1] > d[i]+1){
                d[j+1] = d[i]+1;
            }

        }
        return d[n]-1;
    }
};
