class Solution {
public:
    bool match(char a, char b){
        return b=='?'?true:(a==b);
    }
    bool isMatch(const char *s, const char *p) {
        while (*p && *p != '*'){
            if (*s == 0 || !match(*s, *p)) return false;
            s++, p++;
        }
        int lens = strlen(s), lenp = strlen(p);
        while (lenp && p[lenp-1] != '*'){
            if (lens == 0 || !match(s[lens-1], p[lenp-1])) return false;
            lens--, lenp--;
        }
        if (lenp == 0 && lens != 0){
            return false;
        }
        int f = 0;
        for (int i = 0; i<lenp; i++){
            if (p[i] == '*') continue;
            int j = i+1;
            while (j < lenp && p[j] != '*'){
                j++;
            }
            bool find = false;
            for (int ptr = f; ptr + j-i <= lens; ptr++){
                bool mismatch = false;
                for (int k = 0; k<j-i; k++) if (!match(s[ptr+k], p[i+k])){
                    mismatch = true;
                    break;
                }
                if (!mismatch){
                    f = ptr + j-i;
                    find = true;
                    break;
                }
            }
            if (!find) return false;
            
            i = j;
        }
        return true;
    }
};
