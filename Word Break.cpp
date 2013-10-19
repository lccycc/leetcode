class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> visit;
        for (int i = 0; i<=s.size(); i++){
            visit.push_back(false);
        }
        visit[0] = true;
        for (int i = 0; i<s.size(); i++){
            if (visit[i]){
                for (unordered_set<string>::iterator it = dict.begin();
                        it != dict.end(); it++){
                    int len = (*it).size();
                    if (i + len > s.size()) continue;
                    if (s.substr(i, len).compare(*it) == 0){
                        visit[i+len] = true;
                    }
                }
            }
        }
        return visit[s.size()];
    }
};
