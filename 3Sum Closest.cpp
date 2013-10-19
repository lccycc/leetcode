class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int res = 0;
        bool find = false;
        sort(num.begin(), num.end());
        for (int i = 0; i<num.size(); i++){
            for (int j = i+1, k = num.size()-1; j<k; j++){
                while (k>j && num[i]+num[j]+num[k] > target){
                    k--;
                }
                if (k>j && (!find ||
                        abs(num[i]+num[j]+num[k]-target)<abs(res-target))){
                    find = true;
                    res = num[i]+num[j]+num[k];
                }
                if (k+1<num.size() && (!find ||
                        abs(num[i]+num[j]+num[k+1]-target)<abs(res-target))){
                    find = true;
                    res = num[i]+num[j]+num[k+1];
                }
            }
        }
        return res;
    }
};
