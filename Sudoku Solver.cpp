class Solution {
public:
    bool row[9][9], col[9][9], sqr[3][3][9];
    bool dfs(vector<vector<char> > &b, int x, int y){
        if (y > 8) x++, y = 0;
        if (x > 8) return true;
        if (b[x][y] != '.') return dfs(b, x, y+1);
        for (int i = 0; i<9; i++){
            if (row[x][i] || col[y][i] || sqr[x/3][y/3][i]) continue;
            row[x][i] = col[y][i] = sqr[x/3][y/3][i] = true;
            b[x][y] = '1' + i;
            if (dfs(b, x, y+1)) return true;
            row[x][i] = col[y][i] = sqr[x/3][y/3][i] = false;
        }
        b[x][y] = '.';
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(sqr, 0, sizeof(sqr));
        for (int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                if (board[i][j] != '.'){
                    int c = board[i][j] - '1';
                    row[i][c] = col[j][c] = sqr[i/3][j/3][c] = true;
                }
            }
        }
        dfs(board, 0, 0);
    }
};
