class Solution {
public:
    int divide(int dividend, int divisor) {
        int sgn = -1;
        if (dividend>0){
            sgn*=-1;
            dividend*=-1;
        }
        if (divisor>0){
            sgn*=-1;
            divisor *=-1;
        }
        int res = 0;
        while (dividend <= divisor){
            int deta = -1, cmu = divisor;
            while (dividend - cmu < cmu){
                cmu = cmu + cmu;
                deta = deta + deta;
            }
            dividend -= cmu;
            res += deta;
        }
        return res * sgn;
    }
};
