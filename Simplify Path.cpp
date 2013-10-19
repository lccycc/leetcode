class Solution {
public:
    string simplifyPath(string path) {
        stack<string> sta;
        for (int i = 0; i<path.size();){
            int j;
            for (j = i+1; j<path.size(); j++){
                if (path[j] == '/'){
                    break;
                }
            }
            if (j>i+1){
                string splits = path.substr(i+1, j-i-1);
                if (splits.compare("..") == 0){
                    if (!sta.empty()){
                        sta.pop();
                    }
                }else if (splits.compare(".")!=0){
                    sta.push(splits);
                }
            }
            i = j;
        }
        string res;
        while (!sta.empty()){
            string s = sta.top();
            sta.pop();
            res = "/" + s + res;
        }
        if (res.size() == 0){
            res = "/";
        }
        return res;
    }
};
