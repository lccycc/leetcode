class Solution {
public:
    int id(int ori, int base){
        if (!(ori&1)){
            if (ori > base) return -1;
            return ori;
        }
        if (ori<base) return ori;
        return (ori+base+1)>>1;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        vector<TreeNode *> res;
        int n = num.size();
        if (n == 0) return NULL;
        int k = 1;
        while ((1<<k) < n+1){
            k++;
        }
        int m = (1<<k)-1;
        int base = (1<<k) - (m-n)*2 - 2;
        for (int i = 0; i<n; i++){
            res.push_back(new TreeNode(num[i]));
        }
        for (int i = 0; i<m; i++) if (i&1){
            if (id(i, base) == -1) continue;
            int root = (i^(i+1)) >>1;
            int top = (i ^ root);
            int l = (top | (root>>1));
            int r = l + root + 1;
            if (id(l, base) != -1){
                res[id(i, base)]->left = res[id(l, base)];
            }
            if (id(r, base) != -1){
                res[id(i, base)]->right = res[id(r, base)];
            }
        }
        return res[id((1<<(k-1)) -1, base)];
    }
};
