class LRUCache{
public:
    unordered_map<int, int> kv;
    vector<int> L, R, V, K;
    int n;
    LRUCache(int capacity) {
        n = capacity;
        L.resize(n+2);
        R.resize(n+2);
        V.resize(n+2);
        K.resize(n+2);
        for (int i = 0; i<=n+1; i++){
            L[i] = i-1;
            R[i] = i+1;
            V[i] = -1;
        }
    }
    void upgrade(int rp){
        L[R[rp]] = L[rp];
        R[L[rp]] = R[rp];
        R[rp] = R[0];
        L[rp] = 0;
        R[0] = rp;
        L[R[rp]] = rp;
    }
    int get(int key) {
        if (kv.find(key) != kv.end()){
            int rp = kv[key];
            upgrade(rp);
            return V[rp];
        }
        return -1;
    }
    
    void set(int key, int value) {
        int rp;
        if (kv.find(key) != kv.end()){
            rp = kv[key];
        }else{
            rp = L[n+1];
            if (V[rp] != -1){
                kv.erase(K[rp]);
            }
            kv[key] = rp;
            K[rp] = key;
        }
        V[rp] = value;
        upgrade(rp);
    }
};
