/*
    should use up all char in s
    should be exactly 4 number
    one number should be 0..255
    a number can be a single '0'. if not, should not have leading '0'
*/
class Solution {
public:
    vector<string> res;
    void dfs(vector<string> &ips, int k, string &s, int pnts){
        if (pnts == s.size() && k == 4){
            string tmp = ips[0] + "." + ips[1] + "." + ips[2] + "." + ips[3];
            res.push_back(tmp);
            return ;
        }
        if (pnts == s.size() || k>=4) return ;
        if ((4-k)*3+pnts < s.size()) return;
        if ((4-k) + pnts > s.size()) return ;
        for (int i = 1; i<=3 && i+pnts<=s.size(); i++){
            if (i>1 && s[pnts] == '0') break;
            ips[k] = s.substr(pnts, i);
            int num = atoi(ips[k].c_str());
            if (num > 255) break;
            dfs(ips, k+1, s, pnts+i);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        vector<string> ips;
        ips.resize(4);
        dfs(ips, 0, s, 0);
        return res;
    }
};
