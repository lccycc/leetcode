public:
    string getPermutation(int n, int k) {
        vector<int> step;
        step.push_back(1);
        for (int i = 1; i<n; i++) step.push_back(step[i-1]*i);
        string res;
        k--;
        bool visit[11] = {};
        for (int i = 0; i<n; i++){
            int base = k/step[n-i-1];
            int j;
            for (j = 0; j<n; j++) if (!visit[j]){
                if (base == 0) break;
                base--;
            }
            visit[j] = true;
            k %= step[n-i-1];
            res = res + char('1'+j);
        }
        return res;
    }
};
