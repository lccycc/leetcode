class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, r = n;
        while (l+1<r){
            int mid = (l+r)>>1;
            if (A[l] < A[mid]){
                if (target < A[l] || target >= A[mid]){
                    l = mid;
                }else{
                    r = mid;
                }
            }else{
                if (target < A[mid] || target > A[r-1]){
                    r = mid;
                }else{
                    l = mid;
                }
            }
        }
        if (A[l] == target){
            return l;
        }else{
            return -1;
        }
    }
};
