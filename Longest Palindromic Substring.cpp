class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return 0;
        string p = " " + s + s ;
        for (int i = 0; i<n; i++){
            p[i*2+1] = s[i];
            p[i*2+2] = ' ';
        }
        vector<int> para;
        para.resize(2*n+1);
        para[0] = 0;
        int mid = 0, rmost = 0;
        int mlen = 0, pos = 0;
        for (int i = 1; i<n*2+1; i++){
            int xlen = 0;
            if (rmost >= i){
                xlen = min(para[mid-(i-mid)], rmost-i);
            }
            if (rmost <= i + xlen){
                while (i+xlen+1 < n*2+1 && i-xlen-1>=0 &&
                        p[i+xlen+1] == p[i-xlen-1]){
                    xlen++;
                }
                mid = i;
                rmost = i + xlen;
            }
            para[i] = xlen;
            if (mlen < para[i]){
                mlen = para[i];
                pos = i;
            }
        }
        return s.substr(pos/2-mlen/2-(para[pos] == ' '), mlen);
    }
};
