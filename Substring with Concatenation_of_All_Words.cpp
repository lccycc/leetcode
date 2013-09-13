class Solution {
public:
    vector<string> simpL;
    int search(string s){
        int l = 0, r = simpL.size();
        while (l+1<r){
            int md = (l+r)>>1;
            if (simpL[md].compare(s)<=0){
                l = md;
            }else{
                r = md;
            }
        }
        if (simpL[l].compare(s) == 0){
            return l;
        }else{
            return -1;
        }
    }
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (L.size() == 0){
            for (int i = 0; i<S.size(); i++){
                res.push_back(i);
            }
            return res;
        }
        sort(L.begin(), L.end());
        vector<int> cnt;
        simpL.clear();
        for (int i = 0; i<L.size(); i++){
            int counter = 1;
            while (i+1<L.size() && L[i].compare(L[i+1]) == 0){
                i++;
                counter++;
            }
            cnt.push_back(counter);
            simpL.push_back(L[i]);
        }
        int comLen = L[0].size();
        for (int i = 0; i+L.size()*comLen<=S.size(); i++){
            vector<int> bkcnt = cnt;
            bool err = false;
            for (int j = 0; j<L.size(); j++){
                int pos = i + j * comLen;
                string sub = S.substr(pos, comLen);
                int fd = search(sub);
                if (fd == -1 || --bkcnt[fd]<0) {
                    err = true; break;
                }
            }
            if (!err){
                res.push_back(i);
            }
        }
        return res;
    }
};
