/*
    assume that 0..i-1 and j+1..n-1 have all find their best match
    assume height[i] < height[j]
    if i match some k, i<k<j
        answer = (k-i)*min(height[i], height[k]) <= (k-i)*height[i] < (j-i)*height[i];
    so the best match of i is j.  for k <i or k>j, they have find their best match
*/
class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size()-1, maxarea = 0;
        while (i<j){
            maxarea = max(maxarea, (j-i)*min(height[i], height[j]));
            if (height[i]<height[j]) i++;
            else j--;
        }
        return maxarea;
    }
};
