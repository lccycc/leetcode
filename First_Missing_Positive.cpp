class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i<n; i++) A[i]--;
        n--;
        for (int i = 0; i<=n; i++){
            while (i<=n && A[i] != i){
                int x = A[i];
                if (x>n || x<i || A[x] == x){
                    swap(A[i], A[n]);
                    n--;
                }else{
                    swap(A[i], A[x]);
                }
            }
        }
        return n+2; 
    }
};
