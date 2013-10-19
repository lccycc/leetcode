class Solution {
public:
    vector<vector<bool> > visit;
    void bfs(vector<vector<char> > &board, int x, int y, int n, int m){
        vector<pair<int, int> > h;
        visit[x][y] = true;
        h.push_back(make_pair(x, y));
        const int f[4] = {-1, 0, 1, 0}, g[4] = {0, 1, 0, -1};
        bool meetbd = false;
        for (int i = 0; i<h.size(); i++){
            x = h[i].first, y = h[i].second;
            for (int j = 0; j<4; j++){
                int u = x + f[j], v = y + g[j];
                if (u < 0 || u >= n || v < 0 || v >= m){
                    meetbd = true;
                    continue;
                }
                if (board[u][v] == 'X' || visit[u][v]){
                    continue;
                }
                h.push_back(make_pair(u, v));
                visit[u][v] = true;
            }
        }
        if (!meetbd){
            for (int i = 0; i<h.size(); i++){
                board[h[i].first][h[i].second] = 'X';
            }
        }
    }
    void solve(vector<vector<char>> &board) {
         int n = board.size();
        if (n == 0) return ;
        int m = board[0].size();
        if (m == 0) return ;
        visit.clear();
        for (int i = 0; i<n; i++){
            vector<bool> tmp;
            for (int j = 0; j<m; j++){
                tmp.push_back(0);
            }
            visit.push_back(tmp);
        }
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                if (board[i][j] == 'O' && visit[i][j] == false){
                    bfs(board, i, j, n, m);
                }
            }
        }
        visit.clear();
    }
};
