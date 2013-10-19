class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candy;
        int n = ratings.size();
        candy.resize(n);
        candy[0] = 1;
        stack<int> s;
        s.push(ratings[0]);
        for (int i = 1; i<n; i++){
            candy[i] = 1;
            if (ratings[i] >= s.top()){
                if (ratings[i] > s.top()){
                    candy[i] = max(candy[i], candy[i-1]+1);
                }
                int j = i-1;
                s.pop();
                while (s.size()){
                    s.pop();
                    j--;
                    candy[j] = max(candy[j], candy[j+1]+1);
                }
            }
            s.push(ratings[i]);
        }
        s.pop();
        int j = n-1;
        while (s.size()){
            s.pop();
            j--;
            candy[j] = max(candy[j], candy[j+1]+1);
        }
        int tot = 0;
        for (int i = 0; i<n; i++) tot += candy[i];
        return tot;
    }
};
