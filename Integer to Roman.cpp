class Solution {
public:
    string intToRoman(int num) {
        char dict[] = "IVXLCDM";
        int deta = 1000;
        int ptr = 6;
        string s;
        while (num){
            int c = num/deta;
            if (c <= 3){
                while (c--){
                    s += dict[ptr];
                }
            }else if (c<=8){
                if (c == 4) s += dict[ptr];
                s += dict[ptr+1];
                while (c-- > 5){
                    s += dict[ptr];
                }
            }else{
                s += dict[ptr];
                s += dict[ptr+2];
            }
            num %= deta;
            deta /= 10;
            ptr -=2;
        }
        return s;
    }
};
