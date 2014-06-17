class Solution {
public:
    int upbound(int A[], int n, int target){
        /* minimal i that A[i] > target */
        int l = 0, r = n;
        if (target < A[0]) return 0;
        while (l+1<r){
            int mid = (l+r)/2;
            if (A[mid] <= target) l = mid;
            else r = mid;
        }
        return r;
    }
    int lowbound(int A[], int n, int target){
        /* minimal i that A[i] >= target */
        if (A[0] >= target) return 0;
        int l = 0, r = n;
        while (l+1<r){
            int mid = (l+r)/2;
            if (A[mid] < target) l = mid;
            else r = mid;
        }
        return r;
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res({-1, -1});
        int l = lowbound(A, n, target);
        if (l>=n || A[l] != target) return res;
        int r = upbound(A, n, target);
        res[0] = l;
        res[1] = r-1;
        return res;
    }
};
