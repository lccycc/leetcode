class Solution {
public:
    int atoi(const char *str) {
        while (*str == ' ') str++;
        int flag = -1;
        if (*str == '+') str++;
        else if (*str == '-'){
            flag = 1;
            str++;
        }
        int overflow = (flag<0?INT_MAX:INT_MIN);
        int a = 0;
        while (*str>='0' && *str<='9'){
            int ch = *str-'0';
            str++;
            if (a<INT_MIN/10) return overflow;
            a = a*10;
            if (a<INT_MIN+ch) return overflow;
            a = a-ch;
        }
        if (flag<0 && a==INT_MIN) return overflow;
        return a*flag;
    }
};
