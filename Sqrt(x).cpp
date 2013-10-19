class Solution {
public:
    int sqrt(int x) {
        if (x <= 0) return 0;
        if (x <=3) return 1;
        int l = 2, r = x;
        while (l+1<r){
            int mid = (l+r)/2;
            if (mid <= x/mid){
                l = mid;
            }else{
                r = mid;
            }
        }
        return l;
    }
};

