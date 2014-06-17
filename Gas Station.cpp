/*
    S[i] = Sum{ gas[i] - cost[i], for 0..i }
    S[n-1] should >=0
    for a new start point of t, say G[i] = SUM{ gas[i] - cost[i] for t..i }
    G[i] = S[i] - S[t-1] for i>=t
         = S[n-1] - S[t-1] + S[i] for i<t which >= S[i] - S[t-1]
    so find the t such that S[t-1] is minimal, so all S[i] - S[t-1] >=0
*/

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


