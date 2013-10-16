class Solution {
public:
    vector<string> res;
    vector<int> p;
    vector<vector<int> > goes;
    vector<bool> visit;
    void search(string &s, int k, int cut, unordered_set<string> &dict){
        if (k>=s.size()){
            string tmp = s.substr(0, p[0]);
            for (int i = 1; i<cut; i++){
                tmp = tmp + " " + s.substr(p[i-1], p[i]-p[i-1]);
            }
            res.push_back(tmp);
            return ;
        }
        for (int i = 0; i<goes[k].size(); i++){
            p[cut] = goes[k][i];
            search(s, goes[k][i], cut+1, dict);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        p.resize(s.size());
        res.clear();
        goes.clear();
        goes.resize(s.size());
        visit.clear();
        for (int i = 0; i<=s.size(); i++){
            visit.push_back(false);
        }
        visit[s.size()] = true;
        for (int k = s.size(); k>=0; k--) if (visit[k]){
            for (unordered_set<string>::iterator it = dict.begin(); it!=dict.end(); it++){
                int len = (*it).size();
                if (k - len < 0) continue;
                if (s.substr(k-len, len).compare(*it) == 0){
                    goes[k-len].push_back(k);
                    visit[k-len] = true;
                }
            }
        }
        if (visit[0] == false) return res;
        search(s, 0, 0, dict);
        return res;
    }
};
