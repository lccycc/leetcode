class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        int bas = 1;
        for (int i = 1; i<=n; i++) bas = bas*i;
        string s(n, ' ');
        vector<char> ch;
        for (int i = 0; i<n; i++) ch.push_back('1'+i);
        for (int i = n; i>=1; i--){
            bas = bas/i;
            int let = k / bas;
            k = k%bas;
            s[n-i] = ch[let];
            ch.erase(ch.begin()+let);
        }
        return s;
    }
};
