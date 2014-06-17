/*
    in the Inorder traversal, it's an increasing sequence A by swap two element
    find i that A[i] > A[i+1]. if only one i exists, then swap A[i], A[i+1]
    otherwise A[i1] > A[i1+1], A[i2] > A[i2+1]. swap A[i1] and A[i2].
*/

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
