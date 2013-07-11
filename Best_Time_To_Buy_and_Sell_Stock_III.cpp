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
        int maxv = prices[n-1];
        for (int i = n-2; i>=0; i--){
            r[i] = maxv - prices[i];
            r[i] = max(r[i], 0);
            r[i] = max(r[i], r[i+1]);
            maxv = max(maxv, prices[i]);
        }
        int res = 0;
        for (int  i = 1; i<n-2; i++){
            res = max(res, l[i]+r[i+1]);
        }
        for (int i = 0; i<n; i++){
            res = max(res, l[i]);
            res = max(res, r[i]);
        }
        return res;
    }
};
