class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> tp, rp;
        for (int i = 0; i<=rowIndex; i++){
            tp.push_back(1);
            for (int j = 1; j<i; j++){
                tp[j] = rp[j-1]+rp[j];
            }
            rp = tp;
        }
        return rp;
    }
};
