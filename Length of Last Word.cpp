class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL) return 0;
        int n = strlen(s);
        int j = n-1;
        while (j>=0 && s[j] == ' '){
            j--;
        }
        if (j<0) return 0;
        int i = j;
        while (i>=0 && s[i] != ' ') i--;
        return j-i;
    }
};

