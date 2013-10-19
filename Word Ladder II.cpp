class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, int> d;
        vector<vector<string> > res;
        if (dict.find(start) == dict.end()) return res;
        if (dict.find(end) == dict.end()) return res;
        d[end] = 0;
        vector<string> que;
        que.push_back(end);
        for (int qq = 0; qq < que.size(); qq++){
            string h = que[qq];
            int dh = d[h];
            for (int i = 0; i<h.size(); i++){
                for (int j = 0; j<26; j++){
                    string x = h;
                    x[i] = j + 'a';
                    if (dict.find(x) == dict.end()) continue;
                    if (d.find(x) != d.end()) continue;
                    d[x] = dh +1;
                    que.push_back(x);
                }
            }
        }
        if (d.find(start) == d.end()) return res;
        vector<vector<string> > p[2];
        int pnt = 0;
        p[0].push_back(vector<string>());
        p[0].back().push_back(start);
        for (int xd = d[start]; xd>0; xd--){
            p[pnt^1].clear();
            for (int qq = 0; qq<p[pnt].size(); qq++){
                string h = p[pnt][qq].back();
                int dh = d[h];
                for (int i = 0; i<h.size(); i++){
                    for (int j = 0; j<26; j++){
                        string x = h;
                        x[i] = 'a'+j;
                        if (d.find(x) == d.end()) continue;
                        if (d[x] != dh -1) continue;
                        p[pnt^1].push_back(p[pnt][qq]);
                        p[pnt^1].back().push_back(x);
                    }
                }
            }
            pnt ^= 1;
        }
        return p[pnt];
    }
};
