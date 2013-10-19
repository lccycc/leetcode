class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        if (n <= 1) return;
        int i = n-2, j;
        while (i>=0 && num[i]>=num[i+1]){
            i--;
        }
        if (i>=0){
            j = n-1;
            while (num[j] <= num[i]){
                j--;
            }
            swap(num[i], num[j]);
        }
        for (int l = i+1, r = n-1; l<r; l++, r--){
           swap(num[l], num[r]);
        }
    }
};
