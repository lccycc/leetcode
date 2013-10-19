class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, int> d;
        if (dict.find(start) == dict.end()) return 0;
        if (dict.find(end) == dict.end()) return 0;
        if (start.compare(end) == 0) return 0;
        if (start.size() != end.size()) return 0;
        vector<string> h;
        h.push_back(start);
        d[start] = 1;
        for (int i = 0; i<h.size(); i++){
            string x = h[i];
            int dx = d[x];
            for (int j = 0; j<x.size(); j++){
                for (int k = 0; k<26; k++){
                    string t = x;
                    t[j] = 'a'+k;
                    if (t.compare(end) == 0) return dx+1;
                    if (dict.find(t) == dict.end()) continue;
                    if (d.find(t) != d.end()) continue;
                    d[t] = dx+1;
                    h.push_back(t);
                }
            }
        }
        return 0;
    }
};

