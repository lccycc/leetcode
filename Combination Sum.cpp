class Solution {
public:
    vector<vector<int> > res;
    vector<int> tmp;
    void recur(vector<int> &candidates, int k, int sum){
        /* we want to get to sum using candidates[k..n-1] */
        if (sum == 0) {
            /* output result */
            res.push_back(tmp);
            return ;
        }
        if (sum < 0) return ;
        if (k>=candidates.size()){
            return ;
        }
        tmp.push_back(candidates[k]);
        recur(candidates, k, sum - tmp.back());
        tmp.erase(tmp.end()-1);
        recur(candidates, k+1, sum);
        
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        res.clear();
        tmp.clear();
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        recur(candidates, 0, target);
        return res;
    }
};
