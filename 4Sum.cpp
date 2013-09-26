class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        int n = num.size();
        for (int i = 0; i < n; i++){
            if (i && num[i] == num[i-1]) continue;
            
            for (int j = i+1; j<n; j++){
                if (j > i+1 && num[j] == num[j-1]) continue;
                
                int r = n-1;
                for (int l = j+1; l < r; l++){
                    if (l > j+1 && num[l] == num[l-1]) continue;
                    
                    while (r > l && num[l] + num[r] > target - num[i] - num[j]){
                        r--;
                    }
                    if (r > l && num[l] + num[r] == target - num[i] - num[j]){
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[l]);
                        tmp.push_back(num[r]);
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
};
