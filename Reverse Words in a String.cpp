class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        if (n == 0) return ;
        for (int i = 0; i+i<s.size(); i++){
            swap(s[i], s[n-i-1]);
        }
        for (int i = 0, j; i<n; i = j){
            j = i;
            while (j<n && s[j]==' ') j++;
            if (j>=n) break;
            i = j;
            while (j<n && s[j]!=' ') j++;
            for (int k = 0; k+k<j-i; k++){
                swap(s[i+k], s[j-k-1]);
            }
        }
        int j = 0;
        for (int i = 0; i<n; i++){
            if (s[i]== ' ' && (j == 0 || s[i-1] == ' ')){
                continue;
            }
            s[j++] = s[i];
        }
        if (j>0 && s[j-1] == ' ') j--;
        s.erase(j);
    }
};
