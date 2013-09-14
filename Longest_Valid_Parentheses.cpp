class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<int> lastapp;
        stack<int> que;
        vector<int> sdeta;
        vector<int> f;
        for (int i = 0; i<n+n+1; i++) lastapp.push_back(-1);
        lastapp[n] = 0;
        f.push_back(0);
        sdeta.push_back(0);
        int deta = 0;
        int res = 0;
        for (int i = 0; i<s.size(); i++){
            if (s[i] == '(') deta++;else deta--;
            sdeta.push_back(deta);
            while (!que.empty() && sdeta[que.top()]>= deta){
                que.pop();
            } 
            int lessthen = -1;
            if (!que.empty()) lessthen = que.top();
            que.push(i+1);
            int y = lastapp[n+deta];
            if (y!= -1 && lessthen < y){
                f.push_back(f[y] + (i+1 - y));
                res = max(res, f.back());
            }else{
                f.push_back(0);
            }
            lastapp[n+deta] = i+1;
        }
        return res;
    }
};
