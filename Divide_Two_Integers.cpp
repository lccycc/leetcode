class Solution {
public:
    bool tryadd(int a, int b, int c){
        return a-b<=c;
    }
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
        if (dividend > divisor){
            return 0;
        }
        int res = 0;
        while (dividend <= divisor){
            int deta = -1, cmu = divisor;
            while (tryadd(dividend, cmu, cmu)){
                cmu = cmu + cmu;
                deta = deta + deta;
            }
            dividend -= cmu;
            res += deta;
        }
        return res * sgn;
    }
};
