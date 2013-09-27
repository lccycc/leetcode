class Solution {
public:
    bool col[9][9], sqr[3][3][9];
    int ls[9][11], rs[9][11];
    bool dfs(vector<vector<char> > &b, int x, int y){
        if (y > 8) x++, y = 0;
        if (x > 8) return true;
        if (b[x][y] != '.') return dfs(b, x, y+1);
        int *l = ls[x], *r = rs[x];
        for (int ii = r[0]; ii<=9; ii = r[ii]){
            int i = ii-1;
            if (col[y][i] || sqr[x/3][y/3][i]) continue;
            col[y][i] = sqr[x/3][y/3][i] = true;
            r[l[ii]] = r[ii];
            l[r[ii]] = l[ii];
            b[x][y] = '1' + i;
            if (dfs(b, x, y+1)) return true;
            col[y][i] = sqr[x/3][y/3][i] = false;
            r[l[ii]] = l[r[ii]] = ii;
        }
        b[x][y] = '.';
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        memset(col, 0, sizeof(col));
        memset(sqr, 0, sizeof(sqr));
        for (int i = 0; i<9; i++){
            for (int j = 1; j<=9; j++){
                rs[i][j-1] = ls[i][j+1] = j;
            }
            ls[i][1] = 0;
            rs[i][9] = 10;
        }
        for (int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                if (board[i][j] != '.'){
                    int c = board[i][j] - '1';
                    col[j][c] = sqr[i/3][j/3][c] = true;
                    rs[i][ls[i][c+1]] = rs[i][c+1];
                    ls[i][rs[i][c+1]] = ls[i][c+1];
                }
            }
        }
        dfs(board, 0, 0);
    }
};
