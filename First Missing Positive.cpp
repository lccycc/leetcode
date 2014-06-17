/* Given an unsorted integer array, find the first missing positive integer. */
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        /* for each i = 1...n, see if A[i-1] == i
           if A[i-1] == i, i++;
           otherwise, if A[i-1]<=0 || A[i-1] >n, it's illegal, we swap it with A[n-1] and make n--
           otherwise, A[i-1] should be swap to A[i-1]-1. if A[i-1] == A[A[i-1]-1] it is illegal too
           otherwise swap it.
           this process goes until i>n, we know that for 0..n-1, A[k] = k+1 so we have 1..n, the first missing number is n+1
        */
        for (int i = 1; i<=n;){
            if (A[i-1] == i) i++;
            else if (A[i-1]<=0 || A[i-1] >n || A[i-1] == A[A[i-1]-1]) swap(A[i-1], A[--n]);
            else swap(A[i-1], A[A[i-1]-1]);
        }
        return n+1;
    }
};
