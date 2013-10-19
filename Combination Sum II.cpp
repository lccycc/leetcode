class Solution {
public:
    vector<bool> choose;
    vector<vector<int> > res;
    void dfs(vector<int> &num, int k, int target){
        if (target == 0){
            res.push_back(vector<int>());
            for (int i = 0; i<num.size(); i++){
                if (choose[i]){
                    res.back().push_back(num[i]);
                }
            }
            return ;
        }
        if (k>=num.size()) return ;
        if (target < num[k]) return ;
        if (! (k>0 && num[k] == num[k-1] && choose[k-1]==false)){
            choose[k] = true;
            dfs(num, k+1, target - num[k]);
        }
        choose[k] = false;
        dfs(num, k+1, target);
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        choose.clear();
        for (int i = 0; i<num.size(); i++){
            choose.push_back(false);
        }
        res.clear();
        dfs(num, 0, target);
        return res;
    }
};
