/*
    r[i] means the maximal profit of i..n-1
    for each i, treate it as the sell day of the first operation
    update answer by    prices[i] - MIN(prices[0..i-1]) + r[i+1]
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) return 0;
        vector<int> r;
        r.resize(prices.size()+1);
        int maxp = prices.back();
        for (int i = prices.size()-2; i>=0; i--){
            r[i] = max(r[i+1], maxp - prices[i]);
            maxp = max(maxp, prices[i]);
        }
        int ans = r[0], minp = prices[0];
        for (int i = 1; i<prices.size(); i++){
            ans = max(ans, prices[i] - minp + r[i+1]);
            minp = min(minp, prices[i]);
        }
        return ans;
    }
};
