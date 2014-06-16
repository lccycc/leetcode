/*
class Solution {
public:
    int findKth(int A[], int m, int B[], int n, int k){
        if (m>n) return findKth(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);
        int la = min(k/2, m);
        int lb = k-la;
        if (A[la-1] >= B[lb-1]) return findKth(A, la, B+lb, n-lb, k-lb);
        else return findKth(A+la, m-la, B, lb, k-la);
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m+n)%2){
            return findKth(A, m, B,n, (m+n)/2+1);
        }else{
            int x = findKth(A, m, B,n, (m+n)/2);
            int y = findKth(A, m, B,n, (m+n)/2+1);
            return (x+(double)y)/2.0;
        }
    }
};
*/


class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m>n){
            return findMedianSortedArrays(B, n, A, m);
        }
        if (m < 2){
            if (m == 0) return (B[(n-1)/2] + B[n/2])/2.0;
            if (m == 1){
                if (n & 1){
                    if (n == 1){
                        return (A[0] + B[0]) / 2.0;
                    }
                    int x = B[n/2-1], y = B[n/2+1], z = B[n/2];
                    if (A[0] < x) return (x + z)/2.0;
                    if (A[0] < y) return (A[0] + z)/2.0;
                    return (z + y)/2.0;
                }else{
                    int x = B[(n-1)/2], y = B[n/2];
                    if (A[0] < x) return x;
                    if (A[0] > y) return y;
                    return A[0];
                }
            }
        }

        int xa = 0, ya = 0, xb = 0, yb = 0;
        if(A[(m-1)/2] < B[(n-1)/2]){
            xa = m/2;
        }else{
            xb = n/2;
        }
        if (A[m/2] > B[n/2]){
            ya = m/2;
        }else{
            yb = n/2;
        }
        if (xa != ya){
            xa = min(xa, yb);
            xb = min(xb, ya);
            ya = min(ya, xb);
            yb = min(yb, xa);
        }
        return findMedianSortedArrays(A+xa,m-xa-ya, B+xb, n-xb-yb);
    }
};
