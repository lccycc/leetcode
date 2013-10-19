class Solution {
public:
    int romanToInt(string s) {
        map<char, int> d;
        d['I'] = 1;
        d['V'] = 5;
        d['X'] = 10;
        d['L'] = 50;
        d['C'] = 100;
        d['D'] = 500;
        d['M'] = 1000;
        int res = 0;
        for (int i = 0; i<s.size(); i++){
            if (i+1<s.size() && d[s[i]] < d[s[i+1]]){
                res -= d[s[i]];
            }else{
                res += d[s[i]];
            }
        }
        return res;
    }
};
