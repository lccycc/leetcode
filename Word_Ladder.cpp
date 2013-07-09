class Solution {
public:
    bool ys(string a, string b){
        int s = 0;
        for (unsigned i = 0; i<a.size(); i++) s += (a[i] != b[i]);
        return s == 1;
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        dict.insert(start);
        dict.insert(end);
        map<string, int> d;
        queue<string> q;
        q.push(start);
        d[start] = 1;
        while (!q.empty()){
            string s = q.front();
            q.pop();
            int step = d[s];
            for (unsigned i = 0; i<s.size(); i++){
                char o = s[i];
                for (char c = 'a'; c<='z'; c++){
                    s[i] = c;
                    if (dict.find(s) != dict.end()){
                        if (d.find(s)==d.end()){
                            d[s] = step + 1;
                            q.push(s);
                        }
                    }
                }
                s[i] = o;
            }
        }
        
        return d[end];
    }
};
