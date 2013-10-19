class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int x = n-1;
        for (int i = 0; i<=x; i++){
            while (i<=x && A[i] == elem){
                swap(A[i], A[x]);
                x--;
            }
        }
        return x+1;
    }
};
