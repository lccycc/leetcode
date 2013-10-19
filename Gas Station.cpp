class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int tot = 0, n = gas.size();
        if (n == 0) return -1;
        bool fd = false;
        int mxid, mxtot;
        for (int i = 0; i<gas.size(); i++){
            tot = tot + gas[i] - cost[i];
            if (!fd || mxtot > tot){
                fd = true;
                mxtot = tot;
                mxid = i;
            }
        }
        if (tot < 0) return -1;
        return (mxid+1)%n;
    }
};


