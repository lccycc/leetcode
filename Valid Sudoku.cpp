class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool row[9][9], col[9][9], sqr[3][3][9];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(sqr, 0, sizeof(sqr));
        for (int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                if (board[i][j]!='.'){
                    if (row[i][board[i][j]-'1']) return false;
                    row[i][board[i][j]-'1'] = true;
                    int x = i/3, y = j/3;
                    if (sqr[x][y][board[i][j]-'1']) return false;
                    sqr[x][y][board[i][j]-'1'] = true;
                    if (col[j][board[i][j]-'1']) return false;
                    col[j][board[i][j]-'1'] = true;
                }
            }
        }
        return true;
    }
};
