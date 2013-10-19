class Solution {
public:
    bool err;
    pair<int, int> dfs(TreeNode *t){
        pair<int, int> l, r;
        int lbound = t->val, rbound = t->val;
        if (t->left){
            l = dfs(t->left);
            if (l.second >= t->val) err = true;
            lbound = l.first;
        }
        if (t->right){
            r = dfs(t->right);
            if (r.first <= t->val) err = true;
            rbound = r.second;
        }
        return make_pair(lbound, rbound);
    }
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        err = false;
        dfs(root);
        return !err;
    }
};
