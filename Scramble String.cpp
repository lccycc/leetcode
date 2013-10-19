class Solution {
public:
    unordered_map<int, unordered_map<int, unordered_map<int, bool> > > f, visit;
    string p1, p2;
    bool dfs(int x, int y, int l){
        if (l == 1) return p1[x] == p2[y];
        if (visit[x][y][l]) return f[x][y][l];
        visit[x][y][l] = true;
        int a[256] = {};
        int cnt = 0;
        for (int i = 0; i<l; i++){
            if (a[p1[x+i]]++ == 0) cnt++;
            if (a[p2[y+i]]-- == 1) cnt--;
        }
        if (cnt){
            return f[x][y][l] = false;
        }
        bool res = false;
        for (int i = 1; i<l; i++){
            res |= (dfs(x, y, i) && dfs(x+i, y+i, l-i));
            if (res) break;
            res |= (dfs(x, y+l-i, i) && dfs(x+i, y, l-i));
            if (res) break;
        }
        return f[x][y][l] = res;
    }
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.size() == 0) return true;
        int n = s1.size();
        f.clear();
        visit.clear();
        p1 = s1; p2 = s2;
        return dfs(0, 0, n);
    }
};


