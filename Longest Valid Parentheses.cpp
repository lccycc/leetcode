class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> que;
        que.push(0);
        int res = 0;
        vector<int> f;
        f.push_back(0);
        for (int i = 0; i<s.size(); i++){
            if (s[i] == '('){
                 que.push(i+1);
                 f.push_back(0);
            }
            else{
                if (que.size()>1){
                    que.pop();
                    f.push_back(f[que.top()] + i+1-que.top());
                    res = max(res, f.back());
                }else{
                    que.pop();
                    que.push(i+1);
                    f.push_back(0);
                }
            }
        }
        return res;
    }
};
