class Solution {
public:
    int atoi(const char *str) {
        int sgn = 1;
        while (*str == ' ') str++;
        if (*str == '+') str++;
        if (str[0] != '-'){
            sgn = -1;
        }else{
            str++;
        }
        int n = strlen(str);
        int base = 0;
        int MIN_INT = -2147483648, MAX_INT = 2147483647;
        int over = sgn>0?MIN_INT:MAX_INT;
        for (int i = 0; i<n; i++){
            if (str[i]< '0' || str[i] > '9') return base*sgn;
            if (base < MIN_INT/10) return over;
            base *= 10;
            if (base < MIN_INT + (str[i]-'0')) return over;
            base -= str[i]-'0';
        }
        if (sgn < 0 && base == MIN_INT) return over;
        return base * sgn;
    }
};
