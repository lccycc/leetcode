class Solution {
public:
    string fillspace(int n){
        string res;
        while (n--){
            res = res + " ";
        }
        return res;
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        if (words.size()==0){
            res.push_back(fillspace(L));
            return res;
        }
        for (int i = 0; i<words.size();){
            int deta = L - words[i].size();
            int j;
            for (j = i+1; j<words.size(); j++){
                if (deta < words[j].size() + 1){
                    break;
                }
                deta -= words[j].size() + 1;
            }
            if (j>=words.size()){
                //this is the last line
                string tmp = words[i];
                for (int k = i+1; k<j; k++){
                    tmp = tmp + " " + words[k];
                }
                while (tmp.size()<L){
                    tmp = tmp + " ";
                }
                res.push_back(tmp);
                break;
            }
            int n = j-i-1;
            if (n == 0){
                string tmp = words[i] + fillspace(L - words[i].size());
                res.push_back(tmp);
            }else{
                deta += n;
                int x = deta/n, y = deta%n;
                string tmp = words[i];
                for (int k = i+1; k<j; k++){
                    tmp = tmp + fillspace(x+(y!=0));
                    if (y) y--;
                    tmp = tmp + words[k];
                }
                res.push_back(tmp);
            }
            i = j;
        }
        return res;
    }
};
