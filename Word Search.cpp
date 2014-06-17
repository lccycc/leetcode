class Solution {
public:
    bool dfs(vector<vector<char> > &board, int x, int y, string &word, int k){
        if (k>=word.size()) return true;
        char backup = board[x][y];
        board[x][y] = 0;
        const int f[4] = {-1, 0, 1, 0}, g[4] = {0, 1, 0, -1};
        bool findit = false;
        for (int i = 0; i<4; i++){
            int u = x + f[i], v = y + g[i];
            if (u<0 || v<0 || u>=board.size() || v>=board[u].size()) continue;
            if (board[u][v] != word[k]) continue;
            findit = dfs(board, u, v, word, k+1);
            if (findit) break;
        }
        board[x][y] = backup;
        return findit;
    }
    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0) return true;
        for (int i = 0; i<board.size(); i++){
            for (int j = 0; j<board[i].size(); j++){
                if (board[i][j] == word[0]){
                    if (dfs(board, i, j, word, 1)) return true;
                }
            }
        }
        return false;
    }
};
