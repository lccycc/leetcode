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
			int k = 0;
			if (s.size()) k = s.top()+1;
			l[i] = k;
			s.push(i);
		}
		s = stack<int>();
        for (int i = n-1; i>=0; i--){
			while (s.size() && height[s.top()]>= height[i]){
				s.pop();
			}
			int k = n-1;
			if (s.size()) k = s.top()-1;
			r[i] = k;
			s.push(i);
		}
		int res = 0;
		for (int i = 0; i<n; i++){
			res = max(res, height[i]*(r[i]-l[i]+1));
		}
		return res;
    }
};


