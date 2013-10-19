class Solution {
public:
	vector<int> next;
	void cnext(char* p, int n){
		next.resize(n);
		next[0] = -1;
		for (int i = 1; i<n; i++){
			int t = next[i-1];
			while (t>=0 && p[t] != p[i-1]){
				t = next[t];
			}
			next[i] = t+1;
		}
	}
	char* match(char *s, int m, char *p, int n){
		int t = 0;
		for (int i = 0; i<m; i++){
			while (t>=0 && p[t] != s[i]){
				t = next[t];
			}
			t++;
			if (t >= n) return s+i-n+1;
		}
		return NULL;
	}
    char *strStr(char *haystack, char *needle) {
        if (needle == NULL || haystack == NULL) return NULL;
		int m = strlen(haystack), n = strlen(needle);
		if (n == 0) return haystack;
		cnext(needle, n);
		return match(haystack, m, needle, n);
    }
};
