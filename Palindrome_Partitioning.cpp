class Solution {
public:
    vector<vector<string>> partition(string s) {
        map<int, vector<vector<string>>> m;
        vector<string> tmp;
        m[0].push_back(tmp);
        int n = s.size();
        for (int i = 0; i<n; i++){
            for (int j = i; j<n; j++){
                int l = i, r = j;
                bool err = false;
                while (l<r){
                    if (s[l++] != s[r--]){
                        err = true;
                        break;
                    }
                }
                if (err) continue;
                for (unsigned k = 0; k<m[i].size(); k++){
                    tmp = m[i][k];
                    tmp.push_back(s.substr(i, j-i+1));
                    m[j+1].push_back(tmp);
                }
            }
        }
        return m[n];
    }
};
