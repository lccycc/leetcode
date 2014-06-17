/*
    save the left bound and right bound of each interval.
    the bound inside interval may not be update. but the bounds of both side should be update.
    for a new integer x,
        if x is existed, it's in some interval. ignore x.
        otherwise, build a new interval [x, x]
        look into x-1, if exist, must be a right boundary of some [lbound[x-1], x-1]
            update rbound[lbound[x-1]] <- x, lbound[x] <- lbound[x-1]
        look into x+1, if exist, must be a left boundary of some [x+1, rbound[x+1]]
            update lbound[rbound[x+1] <- lbound[x] !!!
               and rbound[lbound[x]] <- rbound[x+1] !!!
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int, int> lbound, rbound;
        int ans = 0;
        for (int x : num){
            if (lbound.find(x) != lbound.end()) continue;
            lbound[x] = rbound[x] = x;
            if (lbound.find(x-1) != lbound.end()){
                lbound[x] = lbound[x-1];
                rbound[lbound[x]] = x;
            }
            if (lbound.find(x+1) != lbound.end()){
                rbound[x] = rbound[x+1];
                rbound[lbound[x]] = rbound[x];
                lbound[rbound[x]] = lbound[x];
            }
            ans = max(ans, rbound[x] - lbound[x]+1);
        }
        return ans;
    }
};
