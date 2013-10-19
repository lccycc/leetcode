class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while (l<r){
            while (l<r && !(isalpha(s[l])||isdigit(s[l]))){
                l++;
            }
            while (l<r && !(isalpha(s[r])||isdigit(s[r]))){
                r--;
            }
            if (l>=r) break;
            if (s[l]>='A'&&s[l]<='Z'){
                s[l] = s[l] - 'A' + 'a';
            }
            if (s[r]>='A'&&s[r]<='Z'){
                s[r] = s[r] - 'A' + 'a';
            }
            if (s[l] != s[r]){
                return false;
            }
            l++; r--;
        }
        return true;
    }
};
