class Solution {
public:
    int n, m;
    bool dfs(int x, int y, int k, string &word, vector<vector<char> > &board){
        if (k>=word.size()) return true;
        const int f[4] = {-1, 0, 1, 0}, g[4] = {0, 1, 0, -1};
        for (int i = 0; i<4; i++){
            int u = x+f[i], v = y+g[i];
            if (u<0 || u>=n || v<0 || v>=m) continue;
            if (board[u][v] != word[k]) continue;
            board[u][v] = ' ';
            if (dfs(u, v, k+1, word, board)) return true;
            board[u][v] = word[k];
        }
        return false;
    }
            
    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0) return true;
        n = board.size();
        if (n == 0) return false;
        m = board[0].size();
        if (m == 0) return false;
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                if (word[0] == board[i][j]){
                    board[i][j] = ' ';
                    if (dfs(i, j, 1, word, board)) return true;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};
