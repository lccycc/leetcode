class Solution {
public:
    bool ys(string a, string b){
        int s = 0;
        for (unsigned i = 0; i<a.size(); i++) s += (a[i] != b[i]);
        return s == 1;
    }
    map<string, int> d;
       
    void dfs(string s, int k, vector<string> &sta, vector<vector<string>> &res, unordered_set<string> &dict){
        if (k == -1){
            res.push_back(sta);
            return ;
        }
        for (int i = 0; i<s.length(); i++){
            char o = s[i];
            for (char c = 'a'; c<='z'; c++){
                s[i] = c;
                if (dict.find(s) == dict.end()){
                    continue;
                }
                if (d[s] == k+1){
                    sta[k] = s;
                    dfs(s, k-1, sta, res, dict);
                }
            }
            s[i] = o;
        }
    } 
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {

    
        dict.insert(start);
        dict.insert(end);
        d.clear();
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
        
        vector<vector<string>> res;
        if (d[end] == 0){
            return res;
        }
        vector<string> sta;
        for (int i = 0; i<d[end]; i++){
            sta.push_back("");
        }
        sta[d[end]-1] = end;
        dfs(end, d[end]-2, sta, res, dict);
        return res;
        
    }
};
