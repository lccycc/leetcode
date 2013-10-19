class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n= height.size();
        if (n == 0) return 0;
        vector<int> l, r;
        l.resize(n);
        r.resize(n);
        stack<int> s;
        for (int i = 0; i<n; i++){
            while (s.size() && height[s.top()]>= height[i]){
                s.pop();
            }
            l[i] = (s.size() ? l[i] = s.top()+1 : 0);
            s.push(i);
        }
        s = stack<int>();
        for (int i = n-1; i>=0; i--){
            while (s.size() && height[s.top()]>= height[i]){
                s.pop();
            }
            r[i] = (s.size() ? k = s.top()-1 : n-1);
            s.push(i);
        }
        int res = 0;
        for (int i = 0; i<n; i++){
            res = max(res, height[i]*(r[i]-l[i]+1));
        }
        return res;
    }
};


