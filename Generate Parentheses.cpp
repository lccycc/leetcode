class Solution {
public:
    vector<string> res;
    string s;
    void dfs(int k, int x, int n){
        if (k >= n){
            res.push_back(s);
            return ;
        }
        if (x > 0){
            s[k] = ')';
            dfs(k+1, x-1, n);
        }
        if (n - k - 1 >= x + 1){
            s[k] = '(';
            dfs(k+1, x+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        res.clear();
        n = n * 2;
        s = "";
        for (int i = 0; i<n; i++){
            s = s + " ";
        }
        dfs(0, 0, n);
        return res;
    }
};
