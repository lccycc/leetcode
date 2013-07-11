class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n<2) return 0;
        map<int, int> l, r;
        int minv = prices[0];
        for (int i = 1; i<n; i++){
            l[i] = prices[i] - minv;
            l[i] = max(l[i], 0);
            l[i] = max(l[i-1], l[i]);
            minv = min(minv, prices[i]);
        }
        int res = 0;
        for (int i = 0; i<n; i++){
            res = max(res, l[i]);
        }
        return res;
    }
};
