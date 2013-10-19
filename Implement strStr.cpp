class Solution {
public:
    vector<int> makenext(char *s, int n){
        vector<int> next;
        next.push_back(-1);
        for (int i = 1; i<=n; i++){
            int j = next[i-1];
            while (j>=0 && s[j] != s[i-1]){
                j = next[j];
            }
            next.push_back(j+1);
        }
        return next;
    }
    vector<int> match(char *s, int n, char *p, int m, vector<int> &next){
        vector<int> res;
        int j = 0;
        for (int i = 0; i<n; i++){
            while (j>=0 && s[i] != p[j]){
                j = next[j];
            }
            j++;
            if (j>=m){
                res.push_back(i-m+1);
                j = next[j];
            }
        }
        return res;
    }
    char *strStr(char *haystack, char *needle) {
        int m = strlen(needle);
        if (m == 0) return haystack;
        vector<int> next = makenext(needle, m);
        vector<int> res = match(haystack, strlen(haystack), needle, m, next);
        if (res.size()>0){
            return haystack + res[0];
        }else{
            return NULL;
        }
        
    }
};
