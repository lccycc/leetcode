class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if (x < 0 ) return false;
        int acumu = 0, counter = 1, deta = 1;
        while (x/10 >= deta){
            acumu = acumu * 10 + x%10;
            x /= 10;
            deta *= 10;
        }
        if (x >= deta) x/=10;
        return x == acumu;
    }
};
