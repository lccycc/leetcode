class Solution {
public:
    int lowerbound(int A[], int l, int r, int target){
        //find minimal l that A[l] >= target
        while (l+1<r){
            int mid = (l+r)/2;
            if (A[mid] >= target){
                r = mid;
            }else{
                l = mid;
            }
        }
        if (A[l] < target) return l+1;
        return l;
    }
    int upperbound(int A[], int l, int r, int target){
        //find maximal l that A[l] <= target
        while (l+1<r){
            int mid = (l+r)/2;
            if (A[mid] <= target){
                l = mid;
            }else{
                r = mid;
            }
        }
        if (A[l] > target) return l-1;
        return l;
}
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        int l = lowerbound(A, 0, n, target);
        if (l >= n || A[l] != target){
            return res;
        }
        int r = upperbound(A, 0, n, target);
        res[0] = l;
        res[1] = r;
        return res;
    }   
};
