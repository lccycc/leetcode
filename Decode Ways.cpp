class Solution {
public:
    int numDecodings(string s) {
        int f = 0, g = 1;
        if (s.size() == 0) return 0;
        for (int i = 0; i<s.size(); i++){
            int c = 0;
            if (s[i] != '0'){
                c += g;
            }
            if (i && s[i-1]!='0' && (s[i-1]-'0')*10 + s[i]-'0' <=26){
                c += f;
            }
            f = g; g = c;
        }
        return g;
    }
};


