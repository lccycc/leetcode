class Solution {
public:
    vector<string> simpL;
    vector<int> bkcnt;
    int nozero;
    void valid(int kd, int sgn){
        if (kd != -1){
            if (bkcnt[kd] == 0) nozero++;
            bkcnt[kd] += sgn;
            if (bkcnt[kd] == 0) nozero--;
        }
    }
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
        int Lsize = L.size();
        sort(L.begin(), L.end());
        vector<int> cnt;
        simpL.clear();
        for (int i = 0; i<Lsize; i++){
            int counter = 1;
            while (i+1<L.size() && L[i].compare(L[i+1]) == 0){
                i++;
                counter++;
            }
            cnt.push_back(counter);
            simpL.push_back(L[i]);
        }
        int comLen = L[0].size();
        
        for (int start = 0; start<comLen && start + comLen*Lsize <= S.size(); start++){
            vector<int> arr;
            for (int i = start; i<S.size(); i+=comLen){
                arr.push_back(search(S.substr(i, comLen)));
            }
            bkcnt = cnt;
            nozero = bkcnt.size();
            for (int j = 0; j<Lsize; j++){
                valid(arr[j], -1);
            }
            if (nozero == 0){
                res.push_back(start);
            }
            for (int i = 0; i+Lsize<arr.size(); i++){
                valid(arr[i], 1);
                valid(arr[i+Lsize], -1);
                if (nozero == 0){
                    res.push_back(start + comLen*(i+1));
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
