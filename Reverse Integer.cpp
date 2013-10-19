class Solution {
public:
    int reverse(int x) {
        int sgn = 1;
        if (x<0) {
            x = -x;
            sgn = -1;
        }
        int b = 0;
        while (x){
            b = b*10 + x%10;
            x/=10;
        }
        return b*sgn;
    }
};
