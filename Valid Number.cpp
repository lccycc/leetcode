

class Solution {
public:
    bool ischar(char c){
        return c>='0' && c<='9';
    }
    bool isInt(const char *s, int l){
        if (l <= 0) return false;
        for (int i = 0; i<l; i++) if (!ischar(s[i])) return false;
        return true;
    }
    bool isdouble(const char *s, int l){
        int dot = -1;
        for (int i = 0; i<l; i++) if (s[i]=='.'){
            dot = i;
            break;
        }
        if (dot != -1 && l == 1) return false;
        if (dot == -1){
            return isInt(s, l);
        }
        if (dot == 0){
            return isInt(s+1, l-1);
        }
        if (dot == l-1){
            return isInt(s, dot);
        }
        return isInt(s, dot) && isInt(s+dot+1, l-dot-1);
    }
    bool isNumber(const char *s) {
        int e = -1;
        while (*s == ' ') s++;
        if (*s == '+' || *s == '-'){
            s++;
        }
        int n = strlen(s);
        while (n>0 && s[n-1] == ' ') n--;

        for (int i = 0; i<n; i++) if (s[i] == 'e'){
            e = i;
        break;
        }
        if (e == -1){
            return isdouble(s, n);
        }
        if (!isdouble(s, e)) return false;
        s += e+1;
        n-=e+1;
        if (*s == '+' || *s == '-'){
            s++;
            n--;
        }
        return isInt(s, n);
    }
};

