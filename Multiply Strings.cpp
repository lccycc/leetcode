class Solution {
public:
    string multiply(string num1, string num2) {
        int sgn = 1;
        if (num1[0] == '-'){
            num1 = num1.substr(1);
            sgn*=-1;
        }
        if (num2[0] == '-'){
            num2 = num2.substr(1);
            sgn*=-1;
        }
        if (num1.compare("0") == 0 || num2.compare("0") == 0){
            return "0";
        }
        string res;
        int n = num1.size(), m = num2.size();
        for (int i = 0; i<n + m; i++){
            res = res + '0';
        }
        for (int i = n-1; i>=0; i--){
            int t = 0;
            for (int j = m-1; j>=0; j--){
                int x = (num1[i]-'0')*(num2[j]-'0') + (res[i+j+1]-'0') + t;
                res[i+j+1] = x%10 + '0';
                t = x/10;
            }
            res[i] += t;
        }
        if (res[0] == '0'){
            res = res.substr(1);
        }
        if (sgn == -1){
            res = "-" + res;
        }
        return res;
    }
};
