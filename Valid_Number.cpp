class Solution {
public:
    bool isdigit(char c){
        return c>='0' && c<='9';
    }
    bool isInteger(const char *s, int n, bool csig, bool cemp){
        if (n<=0) return cemp;
        if (s[0] == '-' || s[0] == '+'){
            if (!csig) return false;
            s++, n--;
        }
        if (n<=0) return cemp;
        for (int i = 0; i<n; i++){
            if (!isdigit(s[i])){
                return false;
            }
        }
        return true;
    }
    bool isFloat(const char *s, int n){
        if (n<=0) return false;
        int dot = -1;
        bool has = false;
        for (int i = 0; i<n; i++){
            has += isdigit(s[i]);
        }
        if (!has) return false;
        for (int i = 0; i<n; i++) if (s[i] == '.'){
            dot = i;
            break;
        }
        if (dot>=0){
            return isInteger(s, dot, true, true) &&
                    isInteger(s+dot+1, n-dot-1, false, true);
        }else{
            return isInteger(s, n, true, false);
        }
    }
    bool isNumber(const char *s) {
        
        while (*s==' ') s++;
        int e = -1;
        int n = strlen(s);
        while (n>0 && s[n-1] == ' '){
            n--;
        } 
        for (int i = 0; i<n; i++) if (s[i] == 'e'){
            e = i;
            break;
        }
        if (e>=0){
            return isFloat(s, e) && isInteger(s+e+1, n-e-1, true, false);
        }else{
            return isFloat(s, n);
        }
    }
};
