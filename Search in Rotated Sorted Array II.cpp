class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n <= 0) return false;
        int l = 0, r = n;
        while (l+1<r){
            int mid = (l+r)>>1;
            if (A[mid] == target) return true;
            if (A[l] < A[mid]){
                if (target < A[l] || target >= A[mid]){
                    l = mid;
                }else{
                    r = mid;
                }
            }else if (A[mid] < A[r-1]){
                if (target < A[mid] || target > A[r-1]){
                    r = mid;
                }else{
                    l = mid;
                }
            }else if (A[mid] == A[l]){
                return search(A+l+1, mid-l-1, target) || search(A+mid+1, r-mid-1, target);
            }else{
                return search(A+l, mid-l, target) || search (A+mid+1,r-mid-2, target);    
            }
        }
        return A[l] == target;
    }
};
