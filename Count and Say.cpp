class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if (n == 0) return "";
        for (int t = 2; t<=n; t++){
            string tp = "";
            for (int i = 0; i<res.size();){
                int j = i+1;
                while (j<res.size() && res[i] == res[j]) j++;
                char tmp[50];
                sprintf(tmp, "%d%c", j-i, res[i]);
                tp = tp + tmp;
                i = j;
            }
            res = tp;
        }
        return res;
    }
};
