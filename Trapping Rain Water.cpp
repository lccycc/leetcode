class Solution {
public:
    int trap(int A[], int n) {
        int h = 0;
        int tot = 0;
        int deta = 0;
        int pnti = 0;
        for (int i = 0; i<n; i++){
            if (A[i] >= h){
                tot += deta;
                deta = 0;
                h = A[i];
                pnti = i;
            }else{
                deta +=h - A[i];
            }
        }
        h = deta = 0;
        for (int i = n-1; i>=pnti; i--){
            if (A[i] >= h){
                tot += deta;
                deta = 0;
                h = A[i];
            }else{
                deta +=h - A[i];
            }
        }
        return tot;
    }
};
