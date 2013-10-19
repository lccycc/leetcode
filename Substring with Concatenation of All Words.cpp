class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (L.size() == 0){
            for (int i = 0; i<S.size(); i++){
                res.push_back(i);
            }
            return res;
        }
        map<string, int> counter;
        for (int i = 0; i<L.size(); i++){
            counter[L[i]]++;
        }
        int l = L[0].size();
        for (int p = 0; p<l; p++){
            map<string, int> bcnt = counter;
            int cnt = counter.size();
            for (int i = 0; ; i++){
                int x = i*l+p;
                if (x+l>S.size()) break;
                if (--bcnt[S.substr(x, l)] == 0){
                    cnt--;
                }
                if (i>=L.size()-1){
                    int y = x-L.size()*l+l;
                    if (cnt == 0){
                        res.push_back(y);
                    }
                    if (bcnt[S.substr(y, l)]++ == 0){
                        cnt++;
                    }
                }
            }
        }
        return res;
    }
};
