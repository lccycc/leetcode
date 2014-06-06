class Solution {
public:
    int candy(vector<int> &ratings) {
        int sum = 0;
        int last= 1;
        for (int i = 0; i<ratings.size()-1;){
            if (ratings[i] == ratings[i+1]){
                sum += last;
                last = 1;
                i++;
            }else if (ratings[i] < ratings[i+1]){
                sum += last;
                last++;
                i++;
            }else{
                int j = i;
                while (j<ratings.size()-1 && ratings[j] > ratings[j+1]) j++;
                int m = j-i;
                last = max(last, m+1);
                sum += max(last, m+1) + m*(m+1)/2-1;
                i = j;
                last = 1;
            }
        }
        sum += last;
        return sum;
    }
};
