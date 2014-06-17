/*
    the number of graycdde is 2^n
    take care of n=0 and n=1
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i<(1<<n); i++){
            res.push_back(i^(i>>1));
        }
        return res;
    }
};
