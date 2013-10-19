class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n<2) return 0;
        int minv = prices[0];
        int res = 0;
        for (int i = 1; i<n; i++){
            res = max(res, prices[i] - minv);
            minv = min(minv, prices[i]);
        }
        return res;
    }
};
