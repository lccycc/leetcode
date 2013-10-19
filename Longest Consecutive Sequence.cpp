class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, pair<int, int> > h;
        int maxres = 0;
        for (int i = 0; i<num.size(); i++){
            int x = num[i];
            if (h.find(x) != h.end()) continue;
            h[x] = make_pair(x, x);
            if (h.find(x-1) != h.end()){
                h[h[x-1].first].second = x;
                h[x].first = h[x-1].first;
            }
            if (h.find(x+1) != h.end()){
                h[x].second = h[x+1].second;
                h[h[x+1].second].first = h[x].first;
                h[h[x].first].second = h[x+1].second;
            }
            int len = h[x].second - h[x].first+1;
            maxres = max(maxres, len);
        }
        return maxres;
    }
};
