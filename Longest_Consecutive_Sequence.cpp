#include <tr1/unordered_map>

class Solution {
public:
    vector<int> l,r;
    vector<int> fa;
    int findfa(int a){
        return fa[a] == a?a:(fa[a] = findfa(fa[a]));
    }
    void connect(int i, int j){
        i = findfa(i);
        j = findfa(j);
        fa[i] = j;
        l[j] = min(l[j], l[i]);
        r[j] = max(r[j], r[i]);
    }
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> mp;
        l.clear();
        r.clear();
        fa.clear();
        int n = num.size();
        for (int i = 0; i<n; i++){
            l.push_back(num[i]);
            r.push_back(num[i]);
            fa.push_back(i);
            mp[num[i]] = i;
        }
        for (int i = 0; i<n; i++){
            if (mp.find(num[i]-1) != mp.end()){
                connect(i, mp[num[i]-1]);
            }
        }
        int res = 1;
        for (int i = 0; i<n; i++){
            res = max(res, r[i] - l[i] + 1);
        }
        return res;
    }
};
