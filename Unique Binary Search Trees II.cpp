class Solution {
public:
    vector<TreeNode *> dfs(int l, int r){
        vector<TreeNode *> a, p, q;
        if (l>r){
            a.push_back(NULL);
            return a;
        }
        for (int i = l; i<=r; i++){
            p = dfs(l, i-1);
            q = dfs(i+1, r);
            for (int x = 0; x<p.size(); x++){
                for (int y = 0; y<q.size(); y++){
                    TreeNode *t = new TreeNode(i);
                    t->left = p[x];
                    t->right = q[y];
                    a.push_back(t);
                }
            }
        }
        return a;
    }
    vector<TreeNode *> generateTrees(int n) {
        return dfs(1, n);
    }
};


