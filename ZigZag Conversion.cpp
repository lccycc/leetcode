class Solution {
public:
    string convert(string s, int nRows) {
        string res = s;
        if (nRows == 1) return res;
        int n = s.size();
        int l = 2*(nRows-1), r = 0;
        int cnt = 0;
        for (int i = 0; i<nRows; i++){
            int j = i;
            res[cnt++] = s[j];
            while (j < n){
                j += l;
                if (l && j < n){
                    res[cnt++] = s[j];
                }
                j += r;
                if (r && j < n){
                    res[cnt++] = s[j];
                }
            }
            l -= 2;
            r += 2;
        }
        return res;
    }
};
