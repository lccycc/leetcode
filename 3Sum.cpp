class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        int n = num.size();
        if (n < 3) return res;
        sort(num.begin(), num.end());
        for (int i = 0; i<n; i++){
            if (i && num[i] == num[i-1]) continue;
            for (int j = i+1, k = n-1; j<k; j++){
                if (j > i+1 && num[j] == num[j-1]) continue;
                while (k>j && num[i]+num[j]+num[k]> 0){
                    k--;
                }
                if (k>j && num[i] + num[j] + num[k] == 0){
                    res.push_back(vector<int>());
                    res.back().push_back(num[i]);
                    res.back().push_back(num[j]);
                    res.back().push_back(num[k]);
                }
            }
        }
        return res;
    }
};
