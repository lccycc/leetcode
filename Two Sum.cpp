class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        vector<pair<int, int> > st;
        for (int i = 0; i<numbers.size(); i++){
            st.push_back(make_pair(numbers[i], i+1));
        }
        sort(st.begin(), st.end());
        for (int i = 0, j = numbers.size()-1; i < j; i++){
            while (i<j && st[i].first + st[j].first > target){
                j--;
            }
            if (i < j && st[i].first + st[j].first == target){
                res.push_back(st[i].second);
                res.push_back(st[j].second);
                if (res[0] > res[1]) swap(res[0], res[1]);
                break;
            }
        }
        return res;
    }
};
