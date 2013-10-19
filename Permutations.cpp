class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        int n= num.size();
        res.push_back(num);
        if (n < 2) return res;
        while (true){
            int i = n-2;
            while (i>=0 && num[i] >= num[i+1]) i--;

            if (i>=0){
                int j= n-1;
                while (num[j]<=num[i]){
                    j--;
                }
                swap(num[i], num[j]);
                for (int l = i+1, r = n-1; l<r; l++, r--)
                    swap(num[l], num[r]);
                res.push_back(num);
            }else
                break;
        }
        return res;
    }
};
