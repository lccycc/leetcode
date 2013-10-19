class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n<2) return 0;
        vector<int> l, r;
        l.resize(n+1);
        r.resize(n+1);
        int minv = prices[0];
        l[0] = 0;
        for (int i = 1; i<n; i++){
            l[i] = max(prices[i] - minv, l[i-1]);
            minv = min(minv, prices[i]);
        }
        r[n] = r[n-1] = 0;
        int maxv = prices[n-1];
        for (int i = n-2; i>=0; i--){
            r[i] = max(maxv - prices[i], r[i+1]);
            maxv = max(maxv, prices[i]);
        }
        int res = 0;
        for (int  i = 1; i<n; i++){
            res = max(res, l[i]+r[i+1]);
        }
        return res;
    }
};
