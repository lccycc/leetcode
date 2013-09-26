class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res[2];
        int pnt = 0;
        res[pnt].push_back("");
        const char s[][5] = {"", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", " "};
        for (int i = 0; i<digits.size(); i++){
            res[pnt^1].clear();
            int x = digits[i]-'0';
            for (int j = 0; j<res[pnt].size(); j++){
                for (int k = 0; k<strlen(s[x]); k++){
                    res[pnt^1].push_back(res[pnt][j]+s[x][k]);
                }
            }
            pnt ^= 1;
        }
        return res[pnt];
    }
};
