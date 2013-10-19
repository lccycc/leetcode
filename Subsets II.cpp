class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > p;
        p.push_back(vector<int>());

        for (int i = 0; i<S.size();){
            int j = i;
            while (j<S.size() && S[j] == S[i]) j++;

            int psize = p.size();
            for (int k = 0; k<psize; k++){
                for (int t = 1; t<=j-i; t++){
                    p.push_back(p[k]);
                    for (int l = 0; l<t; l++){
                        p.back().push_back(S[i]);
                    }
                }
            }
            i = j;
        }
        return p;
    }
};



