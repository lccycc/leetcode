class Solution {
public:
    vector<vector<int> > res;
    vector<int> s;
    vector<int> ck;
    void dfs(int k, int target){
        if (target == 0){
            vector<int> tmp;
            for (int i = 0; i<s.size(); i++){
                for (int j = 0; j<ck[i]; j++){
                    tmp.push_back(s[i]);
                }
            }
            res.push_back(tmp);
            return ;
        }
        if (k >= s.size()) return ;
        if (target < ck[k]) return ;
        for (ck[k] = 0; target >=0; ck[k]++){
            dfs(k+1, target);
            target -= s[k];
        }
        ck[k] = 0;
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        s = candidates;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        int n = s.size();
        ck.clear();
        for (int i = 0; i<n; i++){
            ck.push_back(0);
        }
        res.clear();
        dfs(0, target);
        return res;
    }
};
