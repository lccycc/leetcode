class Solution {
public:
    void next_pemu(vector<int> &num){
        int n = num.size();
        int i = n-2, j;
        while (i>=0 && num[i]>=num[i+1]){
            i--;
        }
        if (i<0){
            num.clear();
            return ;
        }
        int x = num[i];
        for (j = n-1; j>i; j--) if (num[j]>x) break;
        swap(num[i], num[j]);
        for (j = 0; j+j < n-i-1; j++){
            swap(num[j+i+1], num[n-j-1]);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        do{
            res.push_back(num);
            next_pemu(num);
        }while (num.size());
        return res;
    }
};
