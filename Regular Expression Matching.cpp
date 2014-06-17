class Solution {
public:
/*
    f[i][j]: p[0..i-1] match s[0..j-1]
    if not has star
        f[i][j] = (f[i-1][j-1] && p[i-1] match s[j-1])
    else
        f[i][j] = f[i-1][j] || (f[i][j-1] && p[i-1] match s[j-1])
*/
    bool match(char a, char b){
        return a == '.' || a == b;
    }
    bool isMatch(const char *s, const char *p) {
        vector<bool> f;
        int n = strlen(s);
        f.resize(n+1);
        f[0] = true;
        while (*p){
            char ch = *p++;
            bool hasstar = (*p == '*');
            if (hasstar) p++;
            
            if (!hasstar){
                for (int j = n; j>0; j--)  f[j] = f[j-1] && match(ch, s[j-1]);
                f[0] = false;
            }else{
                for (int j = 1; j<=n; j++) f[j] = f[j] || (f[j-1] && match(ch, s[j-1]));
            }
        }
        return f[n];
    }
};
