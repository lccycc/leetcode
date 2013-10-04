class Solution {
public:
    TreeNode *last, *n1, *n2;
    void dfs(TreeNode *t){
        if (t->left){
            dfs(t->left);
        }
        if (last && t->val < last->val){
            if (!n1) n1 = last, n2 = t;
            else n2 = t;
        }
        last = t;
        if (t->right) dfs(t->right);
    }
    void recoverTree(TreeNode *root) {
        if (root == NULL) return ;
        last = n1 = n2 = NULL;
        dfs(root);
        if (n2)
        swap(n1->val, n2->val);
    }
};
