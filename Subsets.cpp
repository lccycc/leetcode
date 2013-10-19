class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > p;
        p.push_back(vector<int>());
        for (int i = 0; i<S.size(); i++){
            int np = p.size();
            for (int j = 0; j<np; j++){
                p.push_back(p[j]);
                p.back().push_back(S[i]);
            }
        }
        return p;
    }
};
