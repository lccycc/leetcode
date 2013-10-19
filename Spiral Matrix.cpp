class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int n = matrix.size();
        if (n == 0) return res;
        int m = matrix[0].size(); 
        if (m == 0) return res;
        int x = n, y = m;
        int deta = 0;
        while (x>0 && y>0){
            if (x==1){
                for (int i = 0; i<y; i++){
                    res.push_back(matrix[deta][deta+i]);
                }
                break;
            }
            if (y==1){
                for (int i = 0; i<x; i++){
                    res.push_back(matrix[deta+i][deta]);
                }
                break;
            }
            for (int i = 0; i<y-1; i++){
                res.push_back(matrix[deta][deta+i]);
            }
            for (int i = 0; i<x-1; i++){
                res.push_back(matrix[deta+i][deta+y-1]);
            }
            for (int i = y-1; i>0; i--){
                res.push_back(matrix[deta+x-1][deta+i]);
            }
            for (int i = x-1; i>0; i--){
                res.push_back(matrix[deta+i][deta]);
            }

            x-=2;
            y-=2;
            deta++;
        }
        return res;
        
    }
};
