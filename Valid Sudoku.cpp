class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool row[9][9]={}, col[9][9]={}, sqr[3][3][9]={};
        for (int i = 0; i<9; i++) for (int j = 0; j<9; j++){
            char c = board[i][j];
            if (c == '.') continue;
            if (c<'1' || c>'9') return false;
            c -= '1';
            if (row[i][c] || col[j][c] || sqr[i/3][j/3][c]) return false;
            row[i][c] = col[j][c] = sqr[i/3][j/3][c] = true;
        }
        return true;
    }
};
