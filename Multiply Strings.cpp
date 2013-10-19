class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size(), l2 = num2.size();
        if (l1 == 0 || l2 == 0) return "0";
        if (num1.compare("0") == 0 || num2.compare("0") == 0){
            return "0";
        }
        string a;
        for (int i = 0; i<l1+l2-1; i++){
            a = a + "0";
        }
        int la = l1 + l2-1;
        for (int i = 0; i<l1; i++){
            int t = 0;
            int mult = num1[l1-i-1]-'0';
            for (int j = 0; j<l2 || t; j++){
                int x = mult * (j<l2?num2[l2-j-1]-'0':0) + a[la-i-j-1]-'0' + t;
                a[la-i-j-1] = x%10+'0';
                t = x/10;
            }
        }
        if (a[0] == '0') a = a.substr(1);
        return a;
    }
};


