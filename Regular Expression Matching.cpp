class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int n = strlen(s), m = strlen(p);
        vector<bool> a[2];
        for (int i = 0; i<=n; i++){
            a[0].push_back(false);
        }
        a[1] = a[0];
        a[0][0] = true;
        int pnt = 0;
        for (int i = 0; i<m; i++){
            char c = p[i];
            bool star = false;
            if (p[i+1] == '*'){
                i++;
                star = true;
            }
            if (star){
                a[pnt^1] = a[pnt];
            }else{
                for (int j = 0; j<=n; j++){
                    a[pnt^1][j] = 0;
                }
            }
            for (int j = 0; j<n; j++){
                if (a[pnt][j]){
                    for (int k = j; k<n; k++){
                        if (c == '.' || c == s[k]){
                            a[pnt^1][k+1] = true;
                        }else{
                            break;
                        }
                        if (!star){
                            break;
                        }
                    }
                }
            }
            pnt ^= 1;
        }
        return a[pnt][n];
    }
};
