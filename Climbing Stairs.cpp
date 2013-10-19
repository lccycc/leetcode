class Solution {
public:
    int climbStairs(int n) {
        int f = 1, g = 1;
        for (int i = 2; i<=n; i++){
            int c = f+g;
            f = g; g = c;
        }
        return g;
    }
};


