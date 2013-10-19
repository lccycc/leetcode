class Solution {
public:
    int jump(int A[], int n) {
        int res = 0;
        int r = 0, i = 0;
        while (r<n-1){
            int br = r;
            while (i<=br){
                r = max(r, A[i]+i);
                i++;
            }
            if (r == br) return -1;
            res++;
        }
        return res;
    }
};
