class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return string("");
        int maxlen = 0;
        for (int i = 0; i<strs[0].size(); i++){
            bool err = 0;
            for (int j = 1; j<strs.size(); j++){
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]){
                    err = true;
                    break;
                }
            }
            if (!err){
                maxlen = i+1;
            }else{
                break;
            }
        }
        if (maxlen == 0) return string("");
        return strs[0].substr(0, maxlen);
    }
};
