class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        string c = (n > m?a:b);
        int lenc = c.length();
        int t = 0;
        for (int i = 0; i<n || i<m; i++){
            int x = (i<n?a[n-i-1]-'0':0) + (i<m?b[m-i-1]-'0':0) + t;
            c[lenc-i-1] = (x&1)+'0';
            t = (x&2)>>1;
        }
        if (t){
            c = ('1') + c;
        }
        return c;
    }
};
