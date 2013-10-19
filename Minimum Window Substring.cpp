class Solution {
public:
    string minWindow(string S, string T) {
        string res;
        bool find = false;
        int flen = 0;
        int fpos;
        int a[256] = {0};
        int cnt = 0;
        for (int i = 0; i<T.size(); i++){
            if (a[T[i]] == 0) cnt++;
            a[T[i]]++;
        }
        for (int i = 0, j = 0; i<S.size(); i++){
            while (j<S.size() && cnt>0){
                if (--a[S[j]] == 0) cnt--;
                j++;
            }
            if (cnt<=0){
                if (!find || j - i < flen){
                    find = true;
                    flen = j-i;
                    fpos = i;
                }
            }
            if (a[S[i]]++ == 0) cnt++;
        }
        if (!find) return res;
        res = S.substr(fpos, flen);
        return res;
    }
};


