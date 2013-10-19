class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        if (x == 0){
            return 0;
        }
        double res = 1;
        int MAX_INT = 2147483647, MIN_INT = -2147483648;
        if (n<0){
            x = 1/x;
            if (n == MIN_INT){
                n = MAX_INT;
                res *= x;
            }else{
                n = -n;
            }
        }
        while (n){
            if (n&1) res *= x;
            if (n>>=1) x *= x;
        }
        return res;
    }
};
