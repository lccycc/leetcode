class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (L.size() == 0) return res;
        int len = L[0].size();
        map<string, int> num;
        for (string s:L){
            num[s]++;
        }
        for (int start = 0; start < len; start++){
            auto a = num;
            int cnt = a.size();
            for (int i = 0; start+i*len+len<=S.size(); i++){
                auto sub = S.substr(start+i*len, len);
                if (--a[sub] == 0) cnt--;
                if (cnt == 0){
                    res.push_back(start+(i-L.size()+1)*len);
                }
                if (i<L.size()-1) continue;
                sub = S.substr(start+(i-L.size()+1)*len, len);
                if (a[sub]++ == 0) cnt++;
            }
        }
        return res;
    }
};
