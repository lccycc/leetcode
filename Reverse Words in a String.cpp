class Solution {
public:
    void reverseWords(string &s) {
       /* first, reverse s
            second, for each word in s, reverse it again
            third, cut useless space
        */
        for(int l = 0, r = s.size()-1; l<r; l++, r--){
            swap(s[l], s[r]);
        }
        for (int i = 0; i<s.size(); i++) {
            if (s[i] == ' ') continue;
            int j = i;
            while (j < s.size() && s[j] != ' ') j++;
            for (int l = i, r =  j-1; l<r; l++, r--){
                swap(s[l], s[r]);
            }
            i = j;
        }
        /* now, delete useless space */
        int tail = s.size();
        while (tail && s[tail-1]==' ') tail--;
        if (tail ==0){
            s = "";
            return ;
        }
        int pnt = 0;
        for (int i = 0; i<tail; i++){
            if (s[i] != ' ' || (pnt && s[pnt-1] != ' ')){
                s[pnt++] = s[i];
            }
        }
        s = s.substr(0, pnt);
    }
};
