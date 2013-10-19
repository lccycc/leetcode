class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while (k>=0){
            if (i>=0 && (j<0 || A[i]>B[j])){
                A[k--] = A[i--];
            }else{
                A[k--] = B[j--];
            }
        }      
    }
};

