class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<pair<int, pair<int, int> > > tp;
        for (int i = 0; i<num.size(); i++){
            for (int j = i+1; j<num.size(); j++){
                if (j > i+1 && num[j] == num[j-1]) continue;
                tp.push_back(make_pair(num[i] + num[j], make_pair(i, j)));
            }
        }
        sort(tp.begin(), tp.end());
        vector<vector<int> > res;
        for (int i = 0, j = tp.size()-1; i<j; i++){
            if (tp[i].second.first &&
                    num[tp[i].second.first] == num[tp[i].second.first - 1])
                continue;
            while (j > i && tp[j].first + tp[i].first > target){
                j--;
            }
            if (j > i && tp[j].first + tp[i].first == target){
                for (int k = j; k > i && tp[k].first == tp[j].first; k--){
                    if (tp[k].second.first > tp[i].second.second){
                        if (tp[k].second.first > tp[i].second.second + 1 &&
                            num[tp[k].second.first] == num[tp[k].second.first-1]) continue;

                        vector<int> tmp;
                        tmp.push_back(num[tp[i].second.first]);
                        tmp.push_back(num[tp[i].second.second]);
                        tmp.push_back(num[tp[k].second.first]);
                        tmp.push_back(num[tp[k].second.second]);
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
};
