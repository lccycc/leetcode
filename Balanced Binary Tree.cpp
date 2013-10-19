class Solution {
public:
    bool isBalanced(TreeNode *root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode *root, bool &res){
        if (root == NULL || !res){
            return 0;
        }
        int l = dfs(root->left, res), r = dfs(root->right, res);
        if (abs(l-r)>1){
            res = false;
            return 0;
        }
        return max(l, r)+1;
    }
};
