class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool a[256] = {};
        int maxlen = 0;
        for (int i = 0, j = 0; i<s.size(); i++){
            while (a[s[i]]) {
                a[s[j++]] = false;
            }
            a[s[i]] = true;
            maxlen = max(maxlen, i-j+1);
        }
        return maxlen;
    }
};
