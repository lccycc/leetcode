class Solution {
public:
    const int dx[4] = {-1,0,1,0};
    const int dy[4] = {0,1,0,-1};
    void solve(vector<vector<char>> &board) {
        vector<vector<bool>> vis;
        vector<pair<int, int>> q;

        int n = board.size();
        if (n == 0 ) return ;
        int m = board[0].size();
        if (m == 0) return ;
        vector<bool> nb;
        for (int j = 0; j<m; j++){
            nb.push_back(false);
        }
        for (int i = 0; i<n; i++){
            vis.push_back(nb);
        }
        for (int i = 0; i<n; i++){
            for (int  j = 0; j<m; j++){
                if (vis[i][j] == false && board[i][j] == 'O'){
                    bool err = false;
                    q.clear();
                    q.push_back(make_pair(i,j));
                    vis[i][j] = false;
                    for (int t = 0; t<q.size(); t++){
                        int x = q[t].first;
                        int y = q[t].second;
                        for (int r = 0; r<4; r++){
                            int nx = x + dx[r];
                            int ny = y + dy[r];
                            if (nx>=0 && nx<n && ny>=0 && ny<m){
                                if (board[nx][ny] == 'O'){
                                    if (!vis[nx][ny]){
                                        q.push_back(make_pair(nx, ny));
                                        vis[nx][ny] = true;
                                    }
                                }else
                                if (board[nx][ny]!='X'){
                                    err = false;
                                }
                            }else{
                                err = true;
                            }
                        }
                    }
                    if (!err){
                        for (int t = 0; t < q.size(); t++){
                            board[q[t].first][q[t].second] = 'X';
                        }
                    }
                }
            }
        }
    }
};




